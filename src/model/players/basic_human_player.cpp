#include "basic_human_player.hpp"

#include <iostream>
#include <limits.h>

Point BasicHumanPlayer::getMove(const IField* field, Symbol) const {
    int min_x, min_y;
    calcLimits(field->getBoard()->getCells(), min_x, min_y);

    std::cout << "Enter Your move (row, then column):" << std::endl;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    try {
        int y = std::stoi(s1);
        int x = std::stoi(s2);
        return Point{min_x + x, min_y + y};
    } catch(std::invalid_argument&) {
        return Point{INT_MIN, INT_MIN};
    }
}