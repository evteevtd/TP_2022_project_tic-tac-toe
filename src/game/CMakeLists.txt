project(game)

add_library(console_drawer console_drawer.cpp)

add_library(judge judge.cpp)
target_link_libraries(judge console_drawer)

add_library(game INTERFACE)
target_link_libraries(game INTERFACE console_drawer judge)
