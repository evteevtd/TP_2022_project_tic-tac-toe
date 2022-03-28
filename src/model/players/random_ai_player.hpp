#pragma once

#include "iplayer.hpp"

class RandomAIPlayer : public IPlayer {
public:
    Point getMove(const IField*, Symbol) const override;
};
