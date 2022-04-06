project(tic-tac-toe)
cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)


add_subdirectory(interface)
add_subdirectory(model)

target_link_libraries(interface INTERFACE model)

add_executable(target main.cpp)

target_link_libraries(target PUBLIC model interface)
