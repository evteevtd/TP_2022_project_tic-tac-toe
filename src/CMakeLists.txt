cmake_minimum_required(VERSION 3.16.3)
project(tic-tac)

set(CMAKE_CXX_STANDARD 17)

add_executable(target
        main.cpp
        model/basics/point.cpp
        model/basics/figure.cpp
        model/basics/rectangle_board.cpp
        model/basics/map_board.cpp
        model/fields/ifield.cpp
        model/fields/rectangle_field.cpp
        model/players/human_player.cpp
        model/players/random_ai_player.cpp
        game/game.cpp
        interface/igraphics.cpp
        interface/console/console_graphics.cpp
        interface/console/console_inputer.cpp
        interface/console/console_launcher.cpp
    )
