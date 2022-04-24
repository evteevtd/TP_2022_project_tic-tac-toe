#pragma once

#include "iboard.hpp"

#include <vector>

class RectangleBoard : public IBoard {
public:
    RectangleBoard(int x_size, int y_size);

    Symbol at(Point p) const override;
    std::vector<Point> getCells() const override;
    bool setCell(Point p, Symbol s) override;

    IBoard* copy() const override;

private:
    bool checkCell(Point p) const;
    std::vector<std::vector<Symbol>> cells_;
};
