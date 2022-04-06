// #include "console_move_input.hpp"

// ConsoleMoveInput::ConsoleMoveInput(ConsoleGraphics* drawer) : drawer_(drawer) {}

// Point ConsoleMoveInput::getMove() {
//     Point offset = drawer_->getLastOffset();
    
//     std::cout << "Enter Your move (row, then column):" << std::endl;

//     std::string s1, s2;
//     std::cin >> s1 >> s2;

//     try {
//         int y = std::stoi(s1);
//         int x = std::stoi(s2);
//         return offset + Point(x, y);
//     } catch (std::invalid_argument&) {
//         return Point();
//     }
// }
