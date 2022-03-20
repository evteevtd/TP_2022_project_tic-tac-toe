project(basics)

add_library(point point.cpp)

add_library(figure figure.cpp)
target_link_libraries(figure point)

add_library(rectangle_board STATIC rectangle_board.cpp)
target_link_libraries(rectangle_board figure)

add_library(map_board map_board.cpp)
target_link_libraries(map_board figure)


# add_library(board INTERFACE)
# target_link_libraries(board INTERFACE rectangle_board map_board)

add_library(basics INTERFACE)
target_link_libraries(basics INTERFACE point figure rectangle_board map_board)
