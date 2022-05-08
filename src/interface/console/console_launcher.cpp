#include "console_launcher.hpp"

#include <vector>

void ConsoleLauncher::launch() {
    chooseGraphics();
    chooseField();
    choosePlayers();
    game_.run();
}

void ConsoleLauncher::setRectangleField(int x_size, int y_size, int streat_len) {
    auto field = std::make_shared<RectangleField>(x_size, y_size);
    field->addFigures(ClassicFigures::straight(streat_len));
    game_.setField(field);
}

void ConsoleLauncher::chooseCustomRectangleField() {
    print({"choose horisontal and vertical size of a field"});
    auto xy = inputIntegers(2, 1, 15, "you should type two integers from 1 to 15 in one line");

    print({"choose how many in a row should be considered a win"});
    int streat_len = inputInteger(1, std::max(xy[0], xy[1]), "it should be an integer from 1 to " + std::to_string(std::max(xy[0], xy[1])));
    setRectangleField(xy[0], xy[1], streat_len);
}

void ConsoleLauncher::setInfiniteField() {
    auto field = std::make_shared<InfiniteField>();
    field->addFigures(ClassicFigures::straight(5));
    game_.setField(field);
}

void ConsoleLauncher::chooseField() {
    print({ "choose a field to play:",
            "options:",
            "1 : Standard 3x3 field",
            "2 : Standard 5x5 field",
            "3 : Custom rectangle field",
            "4 : Infinite field",
            "please, type a number (1 to 4)"});
    int field_responce = inputInteger(1, 4, "");

    switch (field_responce) {
    case 1:
        setRectangleField(3, 3, 3);
        break;
    case 2:
        setRectangleField(5, 5, 4);
        break;
    case 3:
        chooseCustomRectangleField();
        break;
    case 4:
        setInfiniteField();
        break;
    }
}

void ConsoleLauncher::addPlayer(int option, Symbol s) {
    std::shared_ptr<IPlayer> ptr;
    switch (option) {
    case 0:
        ptr = std::make_shared<HumanPlayer>(graphics_->getInputer());
        break;
    case 1:
        ptr = std::make_shared<RandomAIPlayer>();
        break;
    }
    game_.addPlayer(ptr, s);
}

void ConsoleLauncher::choosePlayers() {
    print({"choose the number of players : 2 to 4"});
    int cnt = inputInteger(2, 4, "the number of players must be an integer between 2 and 4");
    print({ "select player types:",
            "enter " + std::to_string(cnt) + " numbers in one line",
            "enter 0 for every human player, and 1 for every bot"
            });
    std::vector<int> responce = inputIntegers(cnt, 0, 1,
            "you must type " + std::to_string(cnt) + " integers from 0 to 1 in one line");
    for (int i = 0; i < cnt; ++i)
        addPlayer(responce[i], Symbol::FirstDefined + i);
}

void ConsoleLauncher::chooseGraphics() {
    graphics_ = std::make_shared<ConsoleGraphics>();
    game_.setGraphics(graphics_);
}

