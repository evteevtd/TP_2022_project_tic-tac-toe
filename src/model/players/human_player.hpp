#pragma once

#include "iplayer.hpp"
#include "../../interface/igraphics.hpp"

class HumanPlayer : public IPlayer {
public:
    Point getMove(const IField*, Symbol) const override;
    void setMoveInput(IGraphics::Inputer*);
private:
    IGraphics::Inputer* inputer_;
};