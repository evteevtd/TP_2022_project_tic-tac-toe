#pragma once

#include "../model/basics/point.hpp"

class IMoveInput {
public:
    virtual Point getMove() = 0;
    virtual ~IMoveInput() {}
};
