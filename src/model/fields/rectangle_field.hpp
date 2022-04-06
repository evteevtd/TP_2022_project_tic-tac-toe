#pragma once

#include "ifield.hpp"
#include "../basics/rectangle_board.hpp"

class RectangleField : public IField {
public:
    RectangleField(int x_size, int y_size);

    bool setCell(Point, Symbol) override;
    IField* copy() const override;
    void undoMove() override;
    Point getLastMove() const override;

private:
    std::vector<Point> moves_;

    RectangleField(const IBoard*);
};
