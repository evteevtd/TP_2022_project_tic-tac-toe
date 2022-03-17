#include "BasicAIPlayer.hpp"

#include <algorithm>
#include <time.h>
#include <ctime>
#include <map>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <cstdlib>

#include "../../game/out_function.cpp"

template <typename T = std::string>
void alarm(T s = "here", std::string name = "") {
	std::cerr << name << ' ' << s << std::endl;
}

int debug_cnt = 0;
// 
void FewMovesAIPlayer::how_to_go(IField* f, Symbol s, Point& move, int& result, int depth, int time_end) {
	// if (depth == 0 || clock() > time_end) {
	// 	move = Point{0, 0};
	// 	result = 0;
	// 	return;
	// }

	// alarm(++debug_cnt);
	// alarm(depth);

	Board b = f->get_board();
	std::vector<Point> mv = b.get_cells();
	// random_shuffle(mv.begin(), mv.end());
	int min_x = INT_MAX;
	int min_y = INT_MAX;
	int max_x = INT_MIN;
	int max_y = INT_MIN;

	for (auto p : mv) {
		min_x = std::min(min_x, p.x);
		min_y = std::min(min_y, p.y);
		max_x = std::max(max_x, p.x);
		max_y = std::max(max_y, p.y);
	}

	// std::cout << "here1 " << std::endl;

	Symbol other = (s == Symbol::Cross ? Symbol::Zero : Symbol::Cross);

	using std::vector;
	int stat = 0;

	vector<vector<int>> heat_map(max_x - min_x + 1, vector<int>(max_y - min_y + 1, 0));
	vector<vector<int>> flags(max_x - min_x + 1, vector<int>(max_y - min_y + 1, 0));

	vector<Figure> vf = f->get_figures();
	for (auto p : mv) {
		if (b.at(p) != Symbol::Empty) continue;
		for (auto figure : vf) {
			for (int i = 0; i < figure.points.size(); ++i) {
				int cnt[4];
				for (int j = 0; j < 4; ++j) cnt[j] = 0;
				for (auto p1 : figure.shifted(i, p).points) {
					cnt[(int)b.at(p1)]++;
				}
				if (cnt[(int)Symbol::NoCell] != 0) continue;
				if (cnt[(int)Symbol::Cross] != 0 && cnt[(int)Symbol::Zero] != 0) continue;

				int add = 0;
				if (cnt[(int)Symbol::Empty] == 1) {
					if (cnt[(int)s] != 0) {
						flags[p.x - min_x][p.y - min_y] |= (1 << 5);
						add = (1 << (2 * cnt[(int)s]));
					} else {
						flags[p.x - min_x][p.y - min_y] |= (1 << 4);
						add = -(1 << (2 * cnt[(int)other]));
					}
				} else if (cnt[(int)Symbol::Empty] == 2) {
					if (cnt[(int)s] != 0) {
						if (flags[p.x - min_x][p.y - min_y] & (1 << 1)) {
							flags[p.x - min_x][p.y - min_y] |= (1 << 3);
						} else {
							flags[p.x - min_x][p.y - min_y] |= (1 << 1);
						}
						add = (1 << (2 * cnt[(int)s]));
					} else {
						if (flags[p.x - min_x][p.y - min_y] & (1 << 0)) {
							flags[p.x - min_x][p.y - min_y] |= (1 << 2);
						} else {
							flags[p.x - min_x][p.y - min_y] |= (1 << 0);
						}
						add = -(1 << (2 * cnt[(int)other]));
					}
				} else {
					if (cnt[(int)s] != 0) {
						add = (1 << (2 * cnt[(int)s]));
					} else {
						add = -(1 << (2 * cnt[(int)other]));
					}
				}
				heat_map[p.x - min_x][p.y - min_y] += std::abs(add);
				stat += add;
			}
		}
	}
	// std::cout << "here2 " << std::endl;
	int max_flag = 0;
	Point where = {0, 0};
	for (int i = 0; i < max_x - min_x + 1; ++i) {
		for (int j = 0; j < max_y - min_y + 1; ++j) {
			if (flags[i][j] > max_flag) {
				max_flag = flags[i][j];
				where = Point{min_x + i, min_y + j};
			}
		}
	}


	// alarm("p1");

	// out(b);


	bool exact_move = false;
	if (max_flag >= (1 << 2)) {
		move = where;
		if (max_flag & (1 << 5)) {
			result = INT_MAX;
			return;
		} else if (!(max_flag & (1 << 4)) && (max_flag & (1 << 3))) {
			result = INT_MAX;
			return;
		}
		exact_move = true;
	}

	// alarm("p2");
	

	std::vector<std::pair<int, Point>> variants;
	if (!exact_move) {
		for (auto p : mv) {
			if (b.at(p) != Symbol::Empty) continue;
			variants.push_back({heat_map[p.x - min_x][p.y - min_y], p});
		}
		// random_shuffle(variants.rbegin(), variants.rend());
		sort(variants.rbegin(), variants.rend());
		for (int i = 0; i + 1 < variants.size(); ++i) {
			if (rand() % 1000000 > 1000000 / (variants[i].first - variants[i + 1].first + 2)) {
				std::swap(variants[i], variants[i + 1]);
			}
		}
		if (variants.size() == 0) {
			move = {0, 0};
			result = 0;
			return;
		}

		variants.resize(std::min((int)variants.size(), 3 * depth));
	} else {
		variants = {{0, move}};
	}
	if (variants.size() == 1 || variants[0].first >= 3 * variants[1].first) {
		variants.resize(1);
		exact_move = true;
	}

	if (depth == 0 || clock() > time_end) {
		move = variants[0].second;
		result = stat;
		return;		
	}

	move = variants[0].second;
	result = INT_MIN;

	for (auto hp : variants) {
		Point p = hp.second;
		if (!(f->set_cell(p, s))) continue;
		Point opp_move;
		int opp_result = 0;
		// alarm("into");
		how_to_go(f, other, opp_move, opp_result, depth - !exact_move, time_end);
		// alarm("out");
		if (opp_result == INT_MIN + 1) {
			f->undo_move();
			move = p;
			result = INT_MAX;
			return;
		}
		if (-opp_result > result) {
			result = -opp_result;
			move = p;
		}
		f->undo_move();
	}
	// alarm(result, "res");
	return;
}




Point FewMovesAIPlayer::get_move(const IField* field, Symbol symbol) const {
	IField* field_copy = field->copy();

	int end = clock() + CLOCKS_PER_SEC / 8;
	Point move = Point{0, 0};
	int result = INT_MIN;
	srand(time(0));
	for (int depth = 1; ; ++depth) {
		Point new_move;
		int new_result = 0;
		how_to_go(field_copy, symbol, new_move, new_result, depth, end);
		// alarm("hello", "wow");
		if (new_result == INT_MAX) {
			result = new_result;
			move = new_move;
		}
		if (clock() > end) {
			if (new_result > 0) new_result /= 2;
			if (new_result < 0) result /= 2;
			if (new_result > result) {
				result = new_result;
				move = new_move;
			}
			break;
		} else {
			if (new_result > result) {
				result = new_result;
				move = new_move;
			}
		}
	}

	delete field_copy;
	return move;
}
