#include "game.hpp"

Game::Game(IField* f, std::vector<IPlayer*> vp, std::vector<Symbol> vs, IGraphics* g) :
        field_(f), players_(vp), symbols_(vs), graphics_(g) {};

Point Game::getMove(int player_index) {
    Point res;
    while (true) {
        res = players_[player_index]->getMove(field_, symbols_[player_index]);
        if (field_->setCell(res, symbols_[player_index])) return res;
        graphics_->messageError("incorrect move, try again");
    }
    return Point();
}

IPlayer* Game::run() {
    graphics_->startGame(field_, symbols_);

    for (int step = 0; ; ++step) {
        if (!(field_->hasMove())) return nullptr;

        graphics_->drawField(field_);

        int who = step % players_.size();
        Point last_move = getMove(who);

        if (field_->isWinningAt(last_move, symbols_[who])) {
            graphics_->playerWin(field_, symbols_[who]);
            return players_[who];
        }
    }
    return nullptr;
}
