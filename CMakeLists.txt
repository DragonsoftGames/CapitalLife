cmake_minimum_required(VERSION 3.0.0)
project(capitallife VERSION 0.1.0)

file(GLOB srcFiles CONFIGURE_DEPENDS "src/*.cpp")

add_executable(capitallife ${srcFiles})
target_include_directories(
    capitallife
    PRIVATE include
    )

target_link_libraries(capitallife SDL2main SDL2 SDL2_image)