#include "point.hpp"

const Symbol Symbol::NoCell = Symbol(-1);
const Symbol Symbol::Empty = Symbol(0);
const Symbol Symbol::Cross = Symbol(1);
const Symbol Symbol::Zero = Symbol(2);
const Symbol Symbol::FirstDefined = Symbol(1);
const Symbol Symbol::FirstUndefined = Symbol(3);

Symbol::Symbol(int value) : value(value) {}

bool operator==(Symbol lhs, Symbol rhs) {
    return lhs.value == rhs.value;
}
bool operator!=(Symbol lhs, Symbol rhs) {
    return lhs.value != rhs.value;
}
bool operator<(Symbol lhs, Symbol rhs) {
    return lhs.value < rhs.value;
}

Point::Point() : x(INT_MIN), y(INT_MIN) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point Point::operator-(Point other) const {
    return Point{x - other.x, y - other.y};
}

Point Point::operator+(Point other) const {
    return Point{x + other.x, y + other.y};
}

Point Point::rotated() const {
    return Point{-y, x};
}

bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator!=(const Point& lhs, const Point& rhs) {
    return lhs.x != rhs.x || lhs.y != rhs.y;
}
bool operator<(const Point& lhs, const Point& rhs) {
    return std::tie(lhs.x, lhs.y) < std::tie(rhs.x, rhs.y);
}

void calcLimits(const std::vector<Point>& v, int& x_min, int& y_min) {
    x_min = INT_MAX;
    y_min = INT_MAX;
    for (auto p : v) {
        x_min = std::min(x_min, p.x);
        y_min = std::min(y_min, p.y);
    }
}

void calcLimits(const std::vector<Point>& v, int& x_min, int& y_min, int& x_max, int& y_max) {
    calcLimits(v, x_min, y_min);
    x_max = INT_MIN;
    y_max = INT_MIN;
    for (auto p : v) {
        x_max = std::max(x_max, p.x);
        y_max = std::max(y_max, p.y);
    }
}

