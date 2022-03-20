#pragma once

#include "../model/basics/point.hpp"
#include "../model/basics/iboard.hpp"

#include <iostream>
#include <string>
#include <map>


class ConsoleDrawer {
public:
    void draw(const IBoard*, Point last_move = {INT_MIN, INT_MIN});

private:
    inline static const std::string RED = "\033[31m";
    inline static const std::string RESET = "\033[0m";

    inline static const std::map<Symbol, char> symbols = {
        {Symbol::Cross, 'x'},
        {Symbol::Zero, 'o'},
        {Symbol::Empty, ' '},
        {Symbol::NoCell, '#'}
    };

    static int len(int);

    static void space(int cnt);
};
