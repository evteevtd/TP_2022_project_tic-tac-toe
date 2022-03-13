#pragma once

#include "IPlayer.hpp"

class BasicHumanPlayer : public IPlayer {
public:
	Point get_move(const IField*, Symbol) const override;
};