#include "console_drawer.hpp"

int ConsoleDrawer::len(int number) {
    if (number == 0) return 1;
    int ans = 0;
    int pw10 = 1;
    while (pw10 <= number) {
        ans += 1;
        pw10 *= 10;
    }
    return ans;
}

void ConsoleDrawer::space(int cnt) {
    for (int i = 0; i < cnt; ++i) std::cout << ' ';
}

void ConsoleDrawer::draw(const IBoard* board, Point last_move) {
    int x_min, y_min, x_max, y_max;
    std::vector<Point> cells = board->getCells();
    calcLimits(cells, x_min, y_min, x_max, y_max);
    int x_dist = x_max - x_min + 1;
    int y_dist = y_max - y_min + 1;

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
            if (Point{x_min + j, y_min + i} == last_move) std::cout << Colors::RED;
            std::cout << symbols.at(board->at(Point{x_min + j, y_min + i}));
            if (Point{x_min + j, y_min + i} == last_move) std::cout << Colors::RESET;
            std::cout << '|';
        }
        std::cout << '\n';
    }
}
