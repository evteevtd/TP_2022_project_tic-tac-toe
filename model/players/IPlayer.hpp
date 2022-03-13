#pragma once

#include "../model.hpp"

class IPlayer {
public:
	virtual Point get_move(const IField*, Symbol) const = 0;
};
