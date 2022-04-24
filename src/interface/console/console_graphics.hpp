#pragma once

#include "../igraphics.hpp"

#include <iostream>
#include <string>
#include <map>

class ConsoleGraphics : public IGraphics {
public:
    ConsoleGraphics();
    ConsoleGraphics(const ConsoleGraphics&) = delete;
    ConsoleGraphics& operator=(const ConsoleGraphics&) = delete;

    void startGame(const IField*, std::vector<Symbol>) override;
    void drawField(const IField*) override;
    void playerWin(const IField*, Symbol) override;
    void messageError(const std::string&) override;

    class Inputer : public IGraphics::Inputer {
    public:
        Point getMove() override;
        
    private:
        Inputer() {}
        ConsoleGraphics* graphics_;

        friend ConsoleGraphics;
    };

    IGraphics::Inputer* getInputer() override;

private:
    Inputer inputer_;
    Point offset_ = Point(0, 0);

private:
    struct Colors {
        inline static const std::string RED = "\033[31m";
        inline static const std::string RESET = "\033[0m";
    };

    inline static const std::map<Symbol, char> symbols = {
        {Symbol::Cross, 'x'},
        {Symbol::Zero, 'o'},
        {Symbol::Empty, ' '},
        {Symbol::NoCell, '#'}
    };

    static int len(int);
    static void space(int cnt);
};
