cmake_minimum_required(VERSION 3.0.0)
project(capitallife VERSION 0.1.0)

add_executable(capitallife src/main.cpp)

target_link_libraries(capitallife SDL2main SDL2)