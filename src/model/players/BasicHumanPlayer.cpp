#include "BasicHumanPlayer.hpp"

#include <algorithm>
#include <iostream>
#include <limits.h>


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


	using std::cout;

	cout << "Enter Your move (row, then column):" << std::endl;

	std::string s1, s2;
	std::cin >> s1 >> s2;

	try {
		int y = std::stoi(s1);
		int x = std::stoi(s2);
		return Point{min_x + x, min_y + y};
	} catch(std::invalid_argument&) {
		return Point{INT_MIN, INT_MIN};
	}
}