#pragma once

#include "point.hpp"

struct Figure {
    std::vector<Point> points;
    Figure rotated(Point center = Point()) const;
    Figure shifted(int index = 0, Point center = Point()) const;
};
