#include "Basics.hpp"

Symbol Board::at(Point p) const {
	auto it = cells_.find(p);
	if (it == cells_.end()) return Symbol::NoCell;
	return (*it).second;
};

std::vector<Point> Board::get_cells() const {
	std::vector<Point> res;
	for (auto& p : cells_)
		res.push_back(p.first);
	return res;
}

void Board::set_cell(Point p, Symbol s) {
	cells_[p] = s;
}