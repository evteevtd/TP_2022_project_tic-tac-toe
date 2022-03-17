#include "BasicHumanPlayer.hpp"

#include <algorithm>
#include <iostream>



Point BasicHumanPlayer::get_move(const IField* field, Symbol) const {
	// do smth genious;
	Board b = field->get_board();
	auto p = b.get_cells();
	int min_x = 1000000;
	int min_y = 1000000;
	for (auto i : p) {
		min_x = std::min(min_x, i.x);
		min_y = std::min(min_y, i.y);
	}


	// auto p = out(b);

	using std::cout;

	cout << "Enter Your move (row, then column):" << std::endl;	
	int y, x;
	std::cin >> y >> x;
	return Point{min_x + x, min_y + y};
}