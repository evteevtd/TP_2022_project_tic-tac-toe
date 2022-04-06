project(interface)

add_library(game game.cpp)

add_subdirectory(graphics)
add_subdirectory(move_input)

target_link_libraries(console_move_input console_graphics)
target_link_libraries(game graphics)
target_link_libraries(game move_input)

add_library(interface INTERFACE)
target_link_libraries(interface INTERFACE game graphics move_input)
