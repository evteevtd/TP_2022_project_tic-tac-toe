#include "igraphics.hpp"

void IGraphics::startGame(const IField*, std::vector<Symbol>) {}

void IGraphics::playerWin(const IField* field, Symbol) {
    drawField(field);
}

void IGraphics::messageError(const std::string&) {}
