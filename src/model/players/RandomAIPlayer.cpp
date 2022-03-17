#include "RandomAIPlayer.hpp"

#include <algorithm>


Point RandomAIPlayer::get_move(const IField* field, Symbol) const {
	// do smth genious;
	Board b = field->get_board();
	std::vector<Point> p = b.get_cells();
	random_shuffle(p.begin(), p.end());
	for (auto i : p) {
		if (b.at(i) == Symbol::Empty) return i;
	}
	return Point{0, 0};
}