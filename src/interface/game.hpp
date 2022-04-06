#pragma once

#include "../model/basics/point.hpp"
#include "../model/fields/ifield.hpp"
#include "../model/players/iplayer.hpp"
#include "igraphics.hpp"

#include <vector>

class Game {
public:
    Game(IField*, std::vector<IPlayer*>, std::vector<Symbol>, IGraphics*);
    IPlayer* run();

private:
    IField* field_;
    std::vector<IPlayer*> players_;
    std::vector<Symbol> symbols_;
    IGraphics* graphics_;

    Point getMove(int player_index);
};