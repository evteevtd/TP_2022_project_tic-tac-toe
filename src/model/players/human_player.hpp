#pragma once

#include "iplayer.hpp"
#include "../../interface/move_input/imove_input.hpp"

class HumanPlayer : public IPlayer {
public:
    Point getMove(const IField*, Symbol) const override;
    void setMoveInput(IMoveInput*);
private:
    IMoveInput* inputer_;
};