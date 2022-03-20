#pragma once

#include "../basics/point.hpp"
#include "../fields/ifield.hpp"

class IPlayer {
public:
    virtual Point getMove(const IField*, Symbol) const = 0;
};
