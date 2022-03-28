#pragma once

#include <vector>
#include <algorithm>
#include <limits.h>

enum class Symbol : char {
	NoCell = 0,
	Empty = 1,
	Cross = 2,
	Zero = 3
};

struct Point {
	int x, y;
	Point operator-(Point other) const; 
	Point operator+(Point other) const;
	Point rotated() const;
};
bool operator==(const Point& lhs, const Point& rhs);
bool operator<(const Point& lhs, const Point& rhs);

void calcLimits(const std::vector<Point>&, int& x_min, int& y_min);
void calcLimits(const std::vector<Point>&, int& x_min, int& y_min, int& x_max, int& y_max);
