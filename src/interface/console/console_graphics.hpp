#pragma once

#include "../igraphics.hpp"
#include "../../model/fields/infinite_field.hpp"
#include "console_functions.hpp"

#include <iostream>
#include <string>
#include <map>

class ConsoleGraphics : public IGraphics {
public:
    ConsoleGraphics();
    ConsoleGraphics(const ConsoleGraphics&) = delete;
    ConsoleGraphics& operator=(const ConsoleGraphics&) = delete;

    void onGameStart(const IField*, std::vector<Symbol>) override;
    void drawField(const IField*) override;
    void onPlayerWin(const IField*, Symbol) override;
    void onDraw(const IField*) override;
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

    static std::map<Symbol, char> symbols;
    void setSymbols();

    static int len(int);
    static void space(int cnt);
    static void printSymbol(Symbol, bool is_last);
};
