#pragma once

#include <vector>
#include <map>
#include <algorithm>

enum class Symbol {
	NoCell = 0,
	Empty = 1,
	Cross = 2,
	Zero = 3
};

struct Point {
	int x, y;
	Point operator-(Point other) const { return Point{x - other.x, y - other.y}; }
	Point operator+(Point other) const { return Point{x + other.x, y + other.y}; }
	Point rotated() const { return Point{-y, x}; }
};
bool operator==(const Point& lhs, const Point& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator<(const Point& lhs, const Point& rhs) {
	return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
}

struct Figure {
	std::vector<Point> points;
	Figure rotated(Point center = Point()) const;
	Figure shifted(int index = 0, Point center = Point()) const;
};

class Board {
public:
	Symbol at(Point) const;
	std::vector<Point> get_cells() const;
	void set_cell(Point, Symbol);
private:
	std::map<Point, Symbol> cells_;
};
