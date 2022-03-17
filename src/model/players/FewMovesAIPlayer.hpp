#pragma once

#include "IPlayer.hpp"

class FewMovesAIPlayer : public IPlayer {
public:
	Point get_move(const IField*, Symbol) const override;
private:
	static void how_to_go(IField*, Symbol, Point&, int& result, int depth, int time_end);
};
