#pragma once

#include "iboard.hpp"

#include <vector>

class RectangleBoard : public IBoard {
public:
    RectangleBoard(int x_size, int y_size)
        : cells_(std::vector<std::vector<Symbol>>(x_size, std::vector<Symbol>(y_size, Symbol::Empty))) {}

    Symbol at(Point p) const override;
    std::vector<Point> getCells() const override;
    bool setCell(Point p, Symbol s) override;

    IBoard* copy() const override;

private:
    bool checkCell(Point p) const;
    std::vector<std::vector<Symbol>> cells_;
};
