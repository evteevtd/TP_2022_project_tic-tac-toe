#pragma once

#include "point.hpp"

class IBoard {
public:
    virtual Symbol at(Point) const = 0;
    virtual std::vector<Point> getCells() const = 0;
    virtual bool setCell(Point, Symbol) = 0;

    virtual IBoard* copy() const = 0;

    virtual ~IBoard() {}
};
