#include "console_graphics.hpp"

ConsoleGraphics::ConsoleGraphics() {
    inputer_.graphics_ = this;
}

IGraphics::Inputer* ConsoleGraphics::getInputer() {
    return &inputer_;
}

void ConsoleGraphics::drawField(const IField* field) {
    const IBoard* board = field->getBoard();
    Point last_move = field->getLastMove();

    int x_max, y_max;
    std::vector<Point> cells = board->getCells();
    calcLimits(cells, offset_.x, offset_.y, x_max, y_max);
    int x_dist = x_max - offset_.x + 1;
    int y_dist = y_max - offset_.y + 1;

    int spaces = len(y_dist);
    space(spaces);

    for (int j = 0; j < x_dist; ++j) std::cout << ' ' << j;
    std::cout << '\n';

    for (int i = 0; i < y_dist; ++i) {
        std::cout << i;
        space(spaces - len(i));
        std::cout << '|';

        for (int j = 0; j < x_dist; ++j) {
            space(len(j) - 1);
            if (Point{offset_.x + j, offset_.y + i} == last_move) std::cout << Colors::RED;
            std::cout << symbols.at(board->at(Point{offset_.x + j, offset_.y + i}));
            if (Point{offset_.x + j, offset_.y + i} == last_move) std::cout << Colors::RESET;
            std::cout << '|';
        }
        std::cout << '\n';
    }
}

void ConsoleGraphics::messageError(const std::string& s) {
    std::cerr << s << std::endl;
}

int ConsoleGraphics::len(int number) {
    if (number == 0) return 1;
    int ans = 0;
    int pw10 = 1;
    while (pw10 <= number) {
        ans += 1;
        pw10 *= 10;
    }
    return ans;
}

void ConsoleGraphics::space(int cnt) {
    for (int i = 0; i < cnt; ++i) std::cout << ' ';
}

void ConsoleGraphics::startGame(const IField* field, std::vector<Symbol>) {
    const IBoard* board = field->getBoard();
    std::vector<Point> cells = board->getCells();
    calcLimits(cells, offset_.x, offset_.y);
}

