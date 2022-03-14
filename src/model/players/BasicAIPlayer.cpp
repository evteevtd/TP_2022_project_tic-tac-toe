#include "BasicAIPlayer.hpp"

#include <algorithm>
#include <time.h>
#include <ctime>
#include <map>
#include <iostream>

// {+3, 0, -1, -3}

void how_to_go(IField* f, Symbol s, Point& move, int& result, int depth, int time_end) {
	if (depth == 0 || clock() > time_end) {
		move = Point{0, 0};
		result = -1;
		return;
	}
	Board b = f->get_board();
	std::vector<Point> mv = b.get_cells();
	random_shuffle(mv.begin(), mv.end());

	std::vector<Point> loses;
	std::vector<Point> unknowns;
	std::vector<Point> draws;

	for (auto p : mv) {
		if (b.at(p) != Symbol::Empty) continue;
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

Point BasicAIPlayer::get_move(const IField* field, Symbol symbol) const {
	// do smth genious;

	IField* field_copy = field->copy();
	// Board b = field->get_board();

	int end = clock() + 1 * CLOCKS_PER_SEC;

	Point move = Point{0, 0};
	int result = -4;

	for (int depth = 1; depth < 10; ++depth) {
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
			move = new_move;
		}
		// std::cerr << depth << std::endl;
	}

	return move;

	// Board board = field->get_board();

	// Board b = field->get_board();
	// std::vector<Point> p = b.get_cells();
	// random_shuffle(p.begin(), p.end());
	// for (auto i : p) {
	// 	if (b.at(i) == Symbol::Empty) return i;
	// }
	// return Point{0, 0};
}