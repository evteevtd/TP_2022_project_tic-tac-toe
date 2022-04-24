#include "console_graphics.hpp"

ConsoleGraphics::ConsoleGraphics() {
    inputer_.graphics_ = this;
    setSymbols();
}

std::map<Symbol, char> ConsoleGraphics::symbols;

void ConsoleGraphics::setSymbols() {
    if (symbols.empty()) {
        symbols = {
            {Symbol::NoCell, '#'},
            {Symbol::Empty, ' '},
            {Symbol::Cross, 'x'},
            {Symbol::Zero, 'o'},
            {Symbol::FirstUndefined, '+'},
            {Symbol{Symbol::FirstUndefined + 1}, '*'}
        };
    }
}

IGraphics::Inputer* ConsoleGraphics::getInputer() {
    return &inputer_;
}

void ConsoleGraphics::printSymbol(Symbol symbol, bool is_last = false) {
    if (is_last) std::cout << Colors::RED;
    if (symbols.find(symbol) == symbols.end()) {
        std::cout << '?';
    } else {
        std::cout << symbols.at(symbol);
    }
    if (is_last) std::cout << Colors::RESET;
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
            Point move = Point{offset_.x + j, offset_.y + i};
            printSymbol(board->at(move), move == last_move);
            std::cout << '|';
        }
        std::cout << '\n';
    }
}

void ConsoleGraphics::onPlayerWin(const IField* field, Symbol symbol) {
    drawField(field);
    std::cout << "Congratulations to ";
    printSymbol(symbol);
    std::cout << std::endl;
}

void ConsoleGraphics::onDraw(const IField* field) {
    drawField(field);
    std::cout << "Draw!" << std::endl;
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

void ConsoleGraphics::onGameStart(const IField* field, std::vector<Symbol>) {
    if (dynamic_cast<const InfiniteField*>(field) != nullptr) {
        std::cout << "You are playing on an ininite field.\nIt will get bigger as you play." << std::endl;
    }
}

