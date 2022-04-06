#pragma once

#include "imove_input.hpp"
#include "../graphics/console_graphics.hpp"

#include <iostream>

class ConsoleMoveInput : public IMoveInput {
public:
    Point getMove() override;
    ConsoleMoveInput(ConsoleGraphics*);

private:
    ConsoleGraphics* drawer_;
};