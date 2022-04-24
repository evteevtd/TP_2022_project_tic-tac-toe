#include "rectangle_board.hpp"

RectangleBoard::RectangleBoard(int x_size, int y_size) 
        : cells_(std::vector<std::vector<Symbol>>(x_size, std::vector<Symbol>(y_size, Symbol::Empty))) {}

bool RectangleBoard::checkCell(Point p) const {
    return !(p.x < 0 || p.x >= cells_.size() || p.y < 0 || p.y >= cells_[0].size());
}

Symbol RectangleBoard::at(Point p) const {
    if (!checkCell(p)) return Symbol::NoCell;
    return cells_[p.x][p.y];
};

std::vector<Point> RectangleBoard::getCells() const {
    std::vector<Point> res;
    for (int i = 0; i < cells_.size(); ++i)
        for (int j = 0; j < cells_[0].size(); ++j)
            res.push_back(Point{i, j});
    return res;
}

bool RectangleBoard::setCell(Point p, Symbol s) {
    if (!checkCell(p)) return false;
    cells_[p.x][p.y] = s;
    return true;
}

IBoard* RectangleBoard::copy() const {
    RectangleBoard* copy = new RectangleBoard(0, 0);
    copy->cells_ = cells_;
    return copy;
}
