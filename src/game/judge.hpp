#pragma once

#include "../model/basics/point.hpp"
#include "../model/fields/ifield.hpp"
#include "../model/players/iplayer.hpp"
#include "console_drawer.hpp"

#include <vector>

class Judge {
public:
    Judge() {}
    Judge(IField*, std::vector<IPlayer*>, std::vector<Symbol>);
    IPlayer* run();

private:
    IField* field_;
    std::vector<IPlayer*> players_;
    std::vector<Symbol> symbols_;

    ConsoleDrawer drawer_;

    Point getMove(int player_index);
};
