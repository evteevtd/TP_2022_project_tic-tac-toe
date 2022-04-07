#pragma once

#include "game.hpp"

class ILauncher {
public:
    virtual void launch() = 0;
    virtual ~ILauncher() {};
protected:
    Game game_;
};
