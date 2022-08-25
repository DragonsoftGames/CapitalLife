cmake_minimum_required(VERSION 3.0.0)
project(capitallife VERSION 0.1.0)

add_executable(capitallife 
    src/main.cpp
    src/Window.cpp
    src/Scene.cpp

    src/scenes/GameScene.cpp

    src/ecs/Entity.cpp

    src/world/Block.cpp
    src/world/Chunk.cpp
    src/world/Tile.cpp
    src/world/World.cpp
    )
target_include_directories(
    capitallife
    PRIVATE include
    PUBLIC third_party
    )

target_link_libraries(capitallife SDL2main SDL2 SDL2_image)

add_custom_command(TARGET capitallife PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/res/ ${CMAKE_CURRENT_BINARY_DIR}/res/)