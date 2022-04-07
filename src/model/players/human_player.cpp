#include "human_player.hpp"

#include <iostream>
#include <limits.h>

HumanPlayer::HumanPlayer(IGraphics::Inputer* inputer) {
    inputer_ = inputer;
}

Point HumanPlayer::getMove(const IField*, Symbol) const {
    return inputer_->getMove();
}

void HumanPlayer::setMoveInput(IGraphics::Inputer* inputer) {
    inputer_ = inputer;
}