#pragma once

#include <vector>
#include <algorithm>
#include <limits.h>

struct Symbol {
	int value = -1;
	operator int() const { return value; }
	Symbol() = default;
	Symbol(int value);
	const static Symbol NoCell;
	const static Symbol Empty;
	const static Symbol Cross;
	const static Symbol Zero;
	const static Symbol FirstDefined;
	const static Symbol FirstUndefined;
};

bool operator==(Symbol lhs, Symbol rhs);
bool operator!=(Symbol lhs, Symbol rhs);
bool operator<(Symbol lhs, Symbol rhs);


struct Point {
	int x, y;
	Point();
	Point(int, int);
	Point operator-(Point other) const; 
	Point operator+(Point other) const;
	Point rotated() const;
};
bool operator==(const Point& lhs, const Point& rhs);
bool operator!=(const Point& lhs, const Point& rhs);
bool operator<(const Point& lhs, const Point& rhs);

void calcLimits(const std::vector<Point>&, int& x_min, int& y_min);
void calcLimits(const std::vector<Point>&, int& x_min, int& y_min, int& x_max, int& y_max);
