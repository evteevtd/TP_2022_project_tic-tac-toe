#pragma once

#include "IPlayer.hpp"

class HeuristicAIPlayer : public IPlayer {
public:
	Point get_move(const IField*, Symbol) const override;
};
