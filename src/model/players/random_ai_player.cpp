#include "random_ai_player.hpp"

// #include <algorithm>
#include <random>

Point RandomAIPlayer::getMove(const IField* field, Symbol) const {
    // do smth genious;
    const IBoard* b = field->getBoard();
    std::vector<Point> p = b->getCells();

    shuffle(p.begin(), p.end(), std::default_random_engine(0));
    for (auto i : p) {
        if (b->at(i) == Symbol::Empty) return i;
    }
    return Point{0, 0};
}
