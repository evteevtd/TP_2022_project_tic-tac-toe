#include "IField.hpp"

std::vector<Figure> IField::get_figures() const {
	return victorious_;
}

void IField::add_figure(const Figure& f) {
	victorious_.push_back(f);
}

void IField::add_figures(const std::vector<Figure>& figures) {
	for (const auto& f : figures)
		add_figure(f);
}

bool IField::has_move() const {
	Board board = this->get_board();
	std::vector<Point> cells = board.get_cells();
	for (auto p : cells) {
		if (board.at(p) == Symbol::Empty) return true;
	}
	return false;
}

bool IField::is_winning(Symbol symbol) const {
	Board board = this->get_board();
	for (auto pos : board.get_cells()) {
		if (board.at(pos) != symbol) continue;
		for (auto figure : victorious_) {
			bool win = true;
			for (auto point : figure.shifted(0, pos).points) {
				if (board.at(point) != symbol) {
					win = false;
					break;
				}
			}
			if (win) return true;
		}
	}
	return false;
}

bool IField::is_winning_at(Point point, Symbol symbol) const {
	Board board = this->get_board();
	for (auto figure : victorious_) {
		for (int i = 0; i < figure.points.size(); ++i) {
			bool win = true;
			for (auto p : figure.shifted(i, point).points) {
				if (board.at(p) != symbol) {
					win = false;
					break;
				}
			}
			if (win) return true;
		}
	}
	return false;
}
