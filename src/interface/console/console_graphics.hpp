#pragma once

#include "igraphics.hpp"

#include <iostream>
#include <string>
#include <map>

class ConsoleGraphics : public IGraphics {
public:
    void startGame(const IField*, std::vector<Symbol>) override;
    void drawField(const IField*) override;
    void messageError(const std::string&) override;

    Point getLastOffset();

private:
    struct Colors {
        inline static const std::string RED = "\033[31m";
        inline static const std::string RESET = "\033[0m";
    };

    inline static const std::map<Symbol, char> symbols = {
        {Symbol::Cross, 'x'},
        {Symbol::Zero, 'o'},
        {Symbol::Empty, ' '},
        {Symbol::NoCell, '#'}
    };

    static int len(int);

    static void space(int cnt);

    Point last_offset = Point(0, 0);
};
