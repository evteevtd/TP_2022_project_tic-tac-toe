#include "model.hpp"

IField::std::vector<Figure> get_figures() {
	return victorious_;
}

IField::void add_figure(const Figure& f) {
	victorious_.push_back(f);
}

IField::void add_figures(const std::vector<Figure>& figures) {
	for (const auto& f : figures)
		add_figure(f);
}

bool is_winning(Symbol symbol) {
	Board board = *this.get_board();
	for (auto cell : board.cells) {
		if (cell.second; != symbol) continue;
		Point pos = cell.first;
		for (auto figure : victorious_) {
			bool win = true;
			for (auto point : figure.shifted(0, pos)) {
				auto& it = board.cells.find(point);
				if (it == board.cells.end() || (*it).second != symbol) {
					win = false;
					break;
				}
			}
			if (win) return true;
		}
	}
	return false;
}