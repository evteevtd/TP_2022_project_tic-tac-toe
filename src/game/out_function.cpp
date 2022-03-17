#pragma once
#include "Judge.hpp"


#define RESET   "\033[0m"
// #define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
// #define GREEN   "\033[32m"      /* Green */
// #define YELLOW  "\033[33m"      /* Yellow */
// #define BLUE    "\033[34m"      /* Blue */
// #define MAGENTA "\033[35m"      /* Magenta */
// #define CYAN    "\033[36m"      /* Cyan */
// #define WHITE   "\033[37m"      /* White */
// #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
// #define BOLDRED     "\033[1m\033[31m"       Bold Red 
// #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
// #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
// #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
// #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
// #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
// #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */



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


std::pair<int, int> out(Board b, Point last_move = {INT_MIN, INT_MIN}) {
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

	int spaces = len(max_y - min_y - 1);

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
			if (Point{min_x + j, min_y + i} == last_move) cout << RED;
			cout << draw__[b.at(Point{min_x + j, min_y + i})];
			if (Point{min_x + j, min_y + i} == last_move) cout << RESET;
			cout << '|';
		}
		cout << '\n';
	}
	return {min_x, min_y};
}
