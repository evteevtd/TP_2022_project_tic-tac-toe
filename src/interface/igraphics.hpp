#pragma once

#include "../model/basics/point.hpp"
#include "../model/fields/ifield.hpp"

#include <string>
#include <vector>

class IGraphics {
public:
    virtual void onGameStart(const IField*, std::vector<Symbol>);
    virtual void drawField(const IField*) = 0;
    virtual void onPlayerWin(const IField*, Symbol);
    virtual void onDraw(const IField*);
    virtual void messageError(const std::string&);

    class Inputer {
    public:
        virtual Point getMove() = 0;
        virtual ~Inputer() {}
    };

    virtual Inputer* getInputer() = 0;
    virtual ~IGraphics() {}
};
