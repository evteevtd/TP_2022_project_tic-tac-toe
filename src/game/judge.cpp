#include "judge.hpp"

#include <iostream>

Judge::Judge(IField* f, std::vector<IPlayer*> p, std::vector<Symbol> s)
        : field_(f), players_(p), symbols_(s) {}

Point Judge::getMove(int player_index) {
    Point res;
    while (true) {
        res = players_[player_index]->getMove(field_, symbols_[player_index]);
        if (field_->setCell(res, symbols_[player_index])) return res;
        std::cerr << "somthing got wrong, try again" << std::endl;
    }
    return Point{INT_MIN, INT_MIN};
}

IPlayer* Judge::run() {
    Point last_move{INT_MIN, INT_MIN};
    for (int step = 0; ; ++step) {
        if (!(field_->hasMove())) return nullptr;

        drawer_.draw(field_->getBoard(), last_move);

        int who = step % players_.size();
        last_move = getMove(who);

        if (field_->isWinningAt(last_move, symbols_[who])) {
            drawer_.draw(field_->getBoard(), last_move);
            return players_[who];
        }
    }
    return nullptr;
}
