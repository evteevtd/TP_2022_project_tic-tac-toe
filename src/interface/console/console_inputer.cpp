#include "console_graphics.hpp"


Point ConsoleGraphics::Inputer::getMove() {
    std::cout << "Enter Your move (row, then column):" << std::endl;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    try {
        int y = std::stoi(s1);
        int x = std::stoi(s2);
        return graphics_->offset_ + Point(x, y);
    } catch (std::invalid_argument&) {
        return Point();
    }
}
