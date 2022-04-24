
#include "console_launcher.hpp"

#include <limits.h>

void ConsoleLauncher::launch() {
    chooseGraphics();
    chooseField();
    choosePlayers();
    game_.run();
}

void print(const std::vector<std::string>& strings) {
    for (auto str : strings) std::cout << str << std::endl;
}

int input_integer(int from, int to, const std::string& on_error = "something got wrong, try again") {
    std::string responce;
    std::cin >> responce;

    int result = 0;
    while (true) {  
        try {
            result = std::stoi(responce);
            if (from <= result && result <= to) break;
        } catch (std::invalid_argument&) {
            print({on_error});
        }
    }

    return result;
}

void ConsoleLauncher::setRectangleField(int x_size, int y_size, int streat_len) {
    auto field = std::make_shared<RectangleField>(x_size, y_size);
    field->addFigures(ClassicFigures::straight(streat_len));
    game_.setField(field);
}

void ConsoleLauncher::chooseCustomRectangleField() {
    print({"choose horisontal size of a field"});
    int x_size = input_integer(1, 15, "size of a field should be an integer from 1 to 15");
    int y_size = input_integer(1, 15, "size of a field should be an integer from 1 to 15");
    print({"choose how many in the row should be a win"});
    int streat_len = input_integer(1, std::max(x_size, y_size), "it should be an integer and game should be winnable");
    setRectangleField(x_size, y_size, streat_len);
}

void ConsoleLauncher::chooseField() {
    print({ "choose a field to play:",
            "options:",
            "1 : Standard 3x3 field:",
            "2 : Standard 5x5 field:",
            "3 : Custom rectangle field:",
            "please, type a number (1, 2 or 3)"});
    int field_responce = input_integer(1, 3);

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
    print({"choose a game mode:",
            "type 1, if you want to play with a friend",
            "type 2, if you want to play with a bot"});
    int res = input_integer(1, 2);

    switch (res) {
    case 1:
        addPlayer(0, Symbol::Cross);
        addPlayer(0, Symbol::Zero);
        break;
    case 2:
        addPlayer(0, Symbol::Cross);
        addPlayer(1, Symbol::Zero);
        break;
    }
}

void ConsoleLauncher::chooseGraphics() {
    graphics_ = std::make_shared<ConsoleGraphics>();
    game_.setGraphics(graphics_);
}

