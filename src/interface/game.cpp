#include "game.hpp"

void Game::setField(std::shared_ptr<IField> field) {
    field_ = field;
}

void Game::addPlayer(std::shared_ptr<IPlayer> player, Symbol symbol) {
    players_.push_back(player);
    symbols_.push_back(symbol);
}

void Game::setGraphics(std::shared_ptr<IGraphics> graphics) {
    graphics_ = graphics;
}

Point Game::getMove(int player_index) {
    Point res;
    while (true) {
        res = players_[player_index]->getMove(field_.get(), symbols_[player_index]);
        if (field_->setCell(res, symbols_[player_index])) return res;
        graphics_->messageError("incorrect move, try again");
    }
    return Point();
}

std::shared_ptr<IPlayer> Game::run() {
    graphics_->startGame(field_.get(), symbols_);

    for (int step = 0; ; ++step) {
        if (!(field_->hasMove())) return std::shared_ptr<IPlayer>(nullptr);

        graphics_->drawField(field_.get());

        int who = step % players_.size();
        Point last_move = getMove(who);

        if (field_->isWinningAt(last_move, symbols_[who])) {
            graphics_->playerWin(field_.get(), symbols_[who]);
            return players_[who];
        }
    }
    return std::shared_ptr<IPlayer>(nullptr);
}
