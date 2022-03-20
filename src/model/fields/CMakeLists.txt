project(fields)

add_library(ifield ifield.cpp)

add_library(rectangle_field rectangle_field.cpp)
target_link_libraries(rectangle_field ifield)

add_library(fields INTERFACE)
target_link_libraries(fields INTERFACE ifield rectangle_field)
