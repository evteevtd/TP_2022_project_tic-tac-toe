#include "ifield.hpp"

std::vector<Figure> IField::getFigures() const {
    return victorious_;
}

void IField::addFigure(const Figure& f) {
    victorious_.push_back(f);
}

void IField::addFigures(const std::vector<Figure>& figures) {
    for (const auto& f : figures)
        addFigure(f);
}

const IBoard* IField::getBoard() const {
    return board_;
}

bool IField::hasMove() const {
    std::vector<Point> cells = board_->getCells();
    for (auto p : cells) {
        if (board_->at(p) == Symbol::Empty) return true;
    }
    return false;
}

bool IField::isFullFigure(const Figure& figure, Symbol symbol) const {
    for (auto point : figure.points)
        if (board_->at(point) != symbol) return false;
    return true;
}

bool IField::isWinning(Symbol symbol) const {
    for (auto pos : board_->getCells()) {
        if (board_->at(pos) != symbol) continue;
        for (auto figure : victorious_) {
            if (isFullFigure(figure.shifted(0, pos), symbol)) {
                return true;
            }
        }
    }
    return false;
}

bool IField::isWinningAt(Point point, Symbol symbol) const {
    for (auto figure : victorious_) {
        for (int i = 0; i < figure.points.size(); ++i) {
            if (isFullFigure(figure.shifted(i, point), symbol)) {
                return true;
            }
        }
    }
    return false;
}

IField::~IField() {
    delete board_;
}
