#pragma once

#include "ifield.hpp"
#include "../basics/map_board.hpp"

class InfiniteField : public IField {
public:
    InfiniteField();

    bool setCell(Point, Symbol) override;
    IField* copy() const override;
    void undoMove() override;
    Point getLastMove() const override;

private:
    std::vector<Point> moves_; 
    std::vector<int> cnt_changes_;

    InfiniteField(const IBoard*);
};
