#include "random_ai_player.hpp"

#include <algorithm>

Point RandomAIPlayer::getMove(const IField* field, Symbol) const {
    // do smth genious;
    const IBoard* b = field->getBoard();
    std::vector<Point> p = b->getCells();
    random_shuffle(p.begin(), p.end());
    for (auto i : p) {
        if (b->at(i) == Symbol::Empty) return i;
    }
    return Point{0, 0};
}
