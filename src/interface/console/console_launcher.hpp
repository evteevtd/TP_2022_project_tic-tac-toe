#pragma once

#include "../ilauncher.hpp"
#include "../../model/basics/point.hpp"
#include "../../model/basics/classic_figures.hpp"

#include "../../model/fields/rectangle_field.hpp"

#include "../../model/players/human_player.hpp"
#include "../../model/players/random_ai_player.hpp"

#include "console_graphics.hpp"


#include <iostream>
#include <string>
#include <memory>

class ConsoleLauncher : public ILauncher {
public:
    void launch() override;

private:
    std::shared_ptr<IGraphics> graphics_;
    void chooseGraphics();

    void chooseField();
    void setRectangleField(int x_size, int y_size, int streat_len);
    void chooseCustomRectangleField();


    void choosePlayers();
    void addPlayer(int option, Symbol);
};
