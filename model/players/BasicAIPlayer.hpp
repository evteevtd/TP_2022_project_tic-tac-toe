#pragma once

#include "IPlayer.hpp"

class BasicAIPlayer : public IPlayer {
public:
	Point get_move(const IField*, Symbol) const override;
};
