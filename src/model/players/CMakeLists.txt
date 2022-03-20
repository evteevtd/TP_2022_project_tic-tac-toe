project(players)

add_library(basic_human_player basic_human_player.cpp)
add_library(random_ai_player random_ai_player.cpp)

add_library(players INTERFACE)
target_link_libraries(players INTERFACE basic_human_player random_ai_player)
