#pragma once

#include "imove_input.hpp"

#include <iostream>

class ConsoleMoveInput : public IMoveInput {
public:
    Point getMove() override;
};
