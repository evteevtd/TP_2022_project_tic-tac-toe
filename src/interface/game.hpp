#pragma once

#include "../model/basics/point.hpp"
#include "../model/fields/ifield.hpp"
#include "../model/players/iplayer.hpp"
#include "igraphics.hpp"

#include <vector>
#include <memory>

class Game {
public:
    void setField(std::shared_ptr<IField>);
    void addPlayer(std::shared_ptr<IPlayer>, Symbol);
    void setGraphics(std::shared_ptr<IGraphics>);

    std::shared_ptr<IPlayer> run();

private:
    std::shared_ptr<IField> field_;
    std::vector<std::shared_ptr<IPlayer>> players_;
    std::vector<Symbol> symbols_;
    std::shared_ptr<IGraphics> graphics_;

    Point getMove(int player_index);
};