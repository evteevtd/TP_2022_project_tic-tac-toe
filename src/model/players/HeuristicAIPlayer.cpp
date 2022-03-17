#include "BasicAIPlayer.hpp"

#include <algorithm>
#include <time.h>
#include <ctime>
#include <map>
#include <iostream>
#include <limits.h>
#include <math.h>

// {3, 0, -1, -3}


void HeuristicAIPlayer::how_to_go(IField* f, Symbol s, Point& move, int& result, int depth, int time_end) {
	// std::cout << "how_to_go " << ++debug_cnt << std::endl;

	if (depth == 0 || clock() > time_end) {
		move = Point{0, 0};
		result = -1;
		return;
	}

	Board b = f->get_board();
	// out(b);
	// std::cout << std::endl;
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

	std::vector<std::vector<int>> heat_map(max_x - min_x + 1, std::vector<int>(max_y - min_y + 1, 0));
	std::vector<Figure> vf = f->get_figures();
	for (auto p : mv) {
		// std::cout << p.x << ' ' << p.y << '\n';
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
					if (cnt[(int)other] == 0) {
						add = 1000001;
					} else {
						add = 10000;
					}
				} else {
					add = (1 << (2 * (figure.points.size() - cnt[(int)Symbol::Empty])));
				}
				heat_map[p.x - min_x][p.y - min_y] += add;
			}
		}
	}
	// std::cout << "here2 " << std::endl;


	std::vector<std::pair<int, Point>> variants;
	for (auto p : mv) {
		if (b.at(p) != Symbol::Empty) continue;
		variants.push_back({heat_map[p.x - min_x][p.y - min_y], p});
	}
	// random_shuffle(variants.rbegin(), variants.rend());
	sort(variants.rbegin(), variants.rend());

	if (depth != 0) {
		// int size = (int)ceil(pow(depth, 3) * 0.1);
		int size = 3 * depth;
		variants.resize(std::min((int)variants.size(), size));
	}

	std::vector<Point> loses;
	std::vector<Point> unknowns;
	std::vector<Point> draws;

	for (auto hp : variants) {
		Point p = hp.second;
		// if (b.at(p) != Symbol::Empty) continue;
		if (!(f->set_cell(p, s))) continue;
		if (f->is_winning_at(p, s)) {
			f->undo_move();
			move = p;
			result = 3;
			return;
		}
		Point opp_move;
		int opp_result;
		Symbol opp_symbol = (s == Symbol::Cross ? Symbol::Zero : Symbol::Cross);
		how_to_go(f, opp_symbol, opp_move, opp_result, depth - 1, time_end);
		
		if (opp_result == -3) {
			f->undo_move();
			move = p;
			result = 3;
			return;
		}
		if (opp_result == 3) {
			loses.push_back(p);
		} else if (opp_result == 0) {
			draws.push_back(p);
		} else if (opp_result == -1) {
			unknowns.push_back(p);
		}

		f->undo_move();
	}
	if (unknowns.size() != 0) {
		move = unknowns[0];
		result = -1;
		return;
	}
	if (draws.size() != 0) {
		move = draws[0];
		result = 0;
		return;
	}
	if (loses.size() != 0) {
		move = loses[0];
		result = -3;
		return;
	}
	move = Point{0, 0};
	result = 0;
}




Point HeuristicAIPlayer::get_move(const IField* field, Symbol symbol) const {
	IField* field_copy = field->copy();

	int end = clock() + CLOCKS_PER_SEC / 8;
	Point move = Point{0, 0};
	int result = -4;
	for (int depth = 1; ; ++depth) {
		Point new_move;
		int new_result;
		how_to_go(field_copy, symbol, new_move, new_result, depth, end);

		if (clock() > end) {
			if (new_result == 3 || result == -4) {
				result = new_result;
				move = new_move;
			}
			break;
		}
		if (new_result > result) {
			result = new_result;
			move = new_move;
		}
	}

	delete field_copy;
	return move;
}
