#pragma once

#include "../model/basics/point.hpp"
#include "../model/fields/ifield.hpp"

#include <string>
#include <vector>

class IGraphics {
public:
    virtual void startGame(const IField*, std::vector<Symbol>);
    virtual void drawField(const IField*) = 0;
    virtual void playerWin(const IField*, Symbol);
    virtual void messageError(const std::string&);
    virtual ~IGraphics() {}
};