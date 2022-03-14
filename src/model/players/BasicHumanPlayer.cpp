#include "BasicHumanPlayer.hpp"

#include <algorithm>
#include <iostream>


std::map<Symbol, char> draw__ = {
	{Symbol::Cross, 'x'},
	{Symbol::Zero, 'o'},
	{Symbol::Empty, ' '},
	{Symbol::NoCell, '#'}
};

int len(int x) {
	if (x == 0) return 1;
	int ans = 0;
	int pw10 = 1;
	while (pw10 <= x) {
		ans += 1;
		pw10 *= 10;
	}
	return ans;
}

std::pair<int, int> out(Board b) {
	std::vector<Point> p = b.get_cells();

	int min_x = 1000000;
	int min_y = 1000000;

	int max_x = -1000000;
	int max_y = -1000000;
	
	for (auto i : p) {
		min_x = std::min(min_x, i.x);
		min_y = std::min(min_y, i.y);
		max_x = std::max(max_x, i.x);
		max_y = std::max(max_y, i.y);
	}
	max_x += 1;
	max_y += 1;

	using std::cout;

	int spaces = len(max_x - min_x - 1);

	// cout << "  ";
	for (int i = 0; i < spaces; ++i) cout << ' ';

	for (int j = 0; j < max_x - min_x; ++j) {
		cout << ' ' << j;
	}
	cout << '\n';

	for (int i = 0; i < max_y - min_y; ++i) {
		cout << i;
		for (int c = 0; c <= spaces - len(i) - 1; ++c) cout << ' ';
		cout << '|';
		for (int j = 0; j < max_x - min_x; ++j) {
			for (int c = 0; c < len(j) - 1; ++c) cout << ' ';
			cout << draw__[b.at(Point{min_x + j, min_y + i})] << '|';

		}
		cout << '\n';
	}
	return {min_x, min_y};
}

Point BasicHumanPlayer::get_move(const IField* field, Symbol symbol) const {
	// do smth genious;
	Board b = field->get_board();

	auto p = out(b);

	using std::cout;

	cout << "Enter Your move (row, then colomn):" << std::endl;	
	int y, x;
	std::cin >> y >> x;
	return Point{p.first + x, p.second + y};
}