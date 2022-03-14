#pragma once

#include "IPlayer.hpp"

class RandomAIPlayer : public IPlayer {
public:
	Point get_move(const IField*, Symbol) const override;
};
