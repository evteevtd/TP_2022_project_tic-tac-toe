#include "console_graphics.hpp"

Point ConsoleGraphics::Inputer::getMove() {
    print({"Enter Your move (row, then column):"});
   
    std::vector<int> coordinates = inputIntegers(2, INT_MIN, INT_MAX, "");
    return graphics_->offset_ + Point(coordinates[1], coordinates[0]);
}
