#include "rectangle_field.hpp"

RectangleField::RectangleField(int x_size, int y_size) {
    board_ = new RectangleBoard(x_size, y_size);
}

RectangleField::RectangleField(const IBoard* board) {
    board_ = board->copy();
}

bool RectangleField::setCell(Point p, Symbol s) {
    if (board_->at(p) != Symbol::Empty) return false;
    if (!board_->setCell(p, s)) return false;
    moves_.push_back(p);
    return true;
}

IField* RectangleField::copy() const {
    RectangleField* f = new RectangleField(board_);
    f->addFigures(victorious_);
    f->moves_ = moves_;
    return f;
}

void RectangleField::undoMove() {
    board_->setCell(moves_.back(), Symbol::Empty);
    moves_.pop_back();
}

Point RectangleField::getLastMove() const {
    if (moves_.empty()) return Point();
    return moves_.back();
}
