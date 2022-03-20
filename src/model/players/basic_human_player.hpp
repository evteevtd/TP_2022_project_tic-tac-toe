#pragma once

#include "iplayer.hpp"

class BasicHumanPlayer : public IPlayer {
public:
    Point getMove(const IField*, Symbol) const override;
};