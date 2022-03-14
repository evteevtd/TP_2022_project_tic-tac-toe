#include "RectangleField.hpp"

RectangleField::RectangleField(int x_size, int y_size)
	: x_size_(x_size), y_size_(y_size), board_(x_size, std::vector<Symbol>(y_size, Symbol::Empty)) {}
	

Board RectangleField::get_board() const {
	Board board;
	for (int x = 0; x < x_size_; ++x) {
		for (int y = 0; y < y_size_; ++y) {
			board.set_cell(Point{x, y}, board_[x][y]);
		}
	}
	return board;
}

bool RectangleField::set_cell(Point p, Symbol s) {
	if (p.x < 0 || p.y < 0 || p.x >= x_size_ || p.y >= y_size_) return false;
	if (board_[p.x][p.y] != Symbol::Empty) return false;
	board_[p.x][p.y] = s;
	moves_.push_back(p);
	return true;
}

IField* RectangleField::copy() const {
	RectangleField* r = new RectangleField(x_size_, y_size_);
	r->add_figures(victorious_);
	r->board_ = board_;
	r->moves_ = moves_;
	return r;
}

void RectangleField::undo_move() {
	Point p = moves_.back();
	moves_.pop_back();
	board_[p.x][p.y] = Symbol::Empty;
}