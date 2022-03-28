#pragma once

#include "iboard.hpp"

#include <vector>
#include <map>

class MapBoard : public IBoard {
public: 
    Symbol at(Point p) const override;
    std::vector<Point> getCells() const override;
    bool setCell(Point p, Symbol s) override;

    IBoard* copy() const override;

private:
    std::map<Point, Symbol> cells_;
};