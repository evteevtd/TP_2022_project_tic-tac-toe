#include "InfiniteField.hpp"

InfiniteField::InfiniteField() {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			board_.insert({Point{i, j}, Symbol::Empty});
		}
	}
}

Board InfiniteField::get_board() const {
	Board board;
	for (auto p : board_) {
		board.set_cell(p.first, p.second);
	}
	return board;
}

bool InfiniteField::set_cell(Point p, Symbol s) {
	auto it = board_.find(p);
	if (it == board_.end()) return false;
	if ((*it).second != Symbol::Empty) return false;
	board_[p] = s;
	moves_.push_back(p);
	cnt_changes_.push_back(0);
	for (int i = -2; i <= 2; ++i) {
		// for (int j = -1 - (std::abs(i) != 2); j <= 1 + (std::abs(i) != 2); ++j) {
		for (int j = -2; j <= 2; ++j) {
			if (board_.find(p + Point{i, j}) == board_.end()) {
				++cnt_changes_.back();
				board_[p + Point{i, j}] = Symbol::Empty;
				moves_.push_back(p + Point{i, j});
			}
		}
	}
	return true;
}

IField* InfiniteField::copy() const {
	InfiniteField* r = new InfiniteField();
	r->add_figures(victorious_);
	r->board_ = board_;
	r->moves_ = moves_;
	r->cnt_changes_ = cnt_changes_;
	return r;
}

void InfiniteField::undo_move() {
	while (cnt_changes_.back()--) {
		board_.erase(moves_.back());
		moves_.pop_back();
	}
	board_[moves_.back()] = Symbol::Empty;
	cnt_changes_.pop_back();
	moves_.pop_back();
}
