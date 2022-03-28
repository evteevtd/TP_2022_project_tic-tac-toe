#include "rectangle_field.hpp"

RectangleField::RectangleField(int x_size, int y_size) {
    board_ = new RectangleBoard(x_size, y_size);
}

RectangleField::RectangleField(const IBoard* board) {
    board_ = board->copy();
}

bool RectangleField::setCell(Point p, Symbol s) {
    if (!board_->setCell(p, s)) return false;
    moves_.push_back(p);
    return true;
}

IField* RectangleField::copy() const {
    RectangleField* r = new RectangleField(board_);
    r->addFigures(victorious_);
    r->moves_ = moves_;
    return r;
}

void RectangleField::undoMove() {
    board_->setCell(moves_.back(), Symbol::Empty);
    moves_.pop_back();
}
