#include "igraphics.hpp"

void IGraphics::onGameStart(const IField*, std::vector<Symbol>) {
    // default behavior - do nothing
}

void IGraphics::onPlayerWin(const IField* field, Symbol) {
    drawField(field);
}

void IGraphics::onDraw(const IField* field) {
    drawField(field);
}


void IGraphics::messageError(const std::string&) {
    // default behavior - do nothing
}
