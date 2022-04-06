#include "console_move_input.hpp"

Point ConsoleMoveInput::getMove() {
    // int min_x, min_y;
    // calcLimits(field->getBoard()->getCells(), min_x, min_y);

    std::cout << "Enter Your move (row, then column):" << std::endl;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    try {
        int y = std::stoi(s1);
        int x = std::stoi(s2);
        return Point(x, y);
        // return Point{min_x + x, min_y + y};
    } catch (std::invalid_argument&) {
        return Point();
    }
}
