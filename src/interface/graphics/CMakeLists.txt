project(graphics)

add_library(igraphics igraphics.cpp)
add_library(console_graphics console_graphics.cpp)

target_link_libraries(console_graphics igraphics)

add_library(graphics INTERFACE)
target_link_libraries(graphics INTERFACE igraphics console_graphics)
