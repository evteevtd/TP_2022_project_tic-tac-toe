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
	if (board_[p.x][p.y] != Symbol::Empty) return false;
	board_[p.x][p.y] = s;
	return true;
}
