#include "map_board.hpp"


Symbol MapBoard::at(Point p) const {
    auto it = cells_.find(p);
    if (it == cells_.end()) return Symbol::NoCell;
    return (*it).second;
};

std::vector<Point> MapBoard::getCells() const {
    std::vector<Point> res;
    for (auto& p : cells_)
        res.push_back(p.first);
    return res;
}

bool MapBoard::setCell(Point p, Symbol s) {
    cells_[p] = s;
    return true;
}

IBoard* MapBoard::copy() const {
    MapBoard* copy = new MapBoard();
    copy->cells_ = cells_;
    return copy;
}
