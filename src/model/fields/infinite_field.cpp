#include "infinite_field.hpp"

InfiniteField::InfiniteField() {
    board_ = new MapBoard();
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board_->setCell(Point(i, j), Symbol::Empty);
}

InfiniteField::InfiniteField(const IBoard* board) {
    board_ = board->copy();
}

bool InfiniteField::setCell(Point p, Symbol s) {
    if (board_->at(p) != Symbol::Empty) return false;
    board_->setCell(p, s);
    moves_.push_back(p);
    cnt_changes_.push_back(0);
    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (board_->at(p + Point{i, j}) != Symbol::NoCell) continue;
            board_->setCell(p + Point{i, j}, Symbol::Empty);
            moves_.push_back(p + Point{i, j});
            ++cnt_changes_.back();
        }
    }
    return true;
}

IField* InfiniteField::copy() const {
    InfiniteField* f = new InfiniteField(board_);
    f->addFigures(victorious_);
    f->moves_ = moves_;
    f->cnt_changes_ = cnt_changes_;
    return f;
}

void InfiniteField::undoMove() {
    while (cnt_changes_.back()--) {
        board_->setCell(moves_.back(), Symbol::NoCell);
        moves_.pop_back();
    }
    board_->setCell(moves_.back(), Symbol::Empty);
    cnt_changes_.pop_back();
    moves_.pop_back();
}

Point InfiniteField::getLastMove() const {
    if (moves_.empty()) return Point();
    return moves_[moves_.size() - cnt_changes_.back() - 1];
}
