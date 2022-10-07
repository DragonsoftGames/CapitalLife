cmake_minimum_required(VERSION 3.0.0)
project(capitallife VERSION 0.1.0)

include_directories(third_party/entt/src)
add_subdirectory(third_party/entt)

include_directories(third_party/OpenSimplexNoise/OpenSimplexNoise)
add_library(OpenSimplexNoise third_party/OpenSimplexNoise/OpenSimplexNoise/OpenSimplexNoise.cpp)

add_executable(capitallife 
src/main.cpp
src/Window.cpp
src/TextureManager.cpp
src/Input.cpp
src/Scene.cpp

src/math/Vec2.cpp

src/scenes/GameScene.cpp

src/ecs/Entity.cpp

src/world/Block.cpp
src/world/Chunk.cpp
src/world/Tile.cpp
src/world/World.cpp
src/world/WorldGenerator.cpp

src/inventory/Item.cpp
src/inventory/Inventory.cpp
)
target_include_directories(
    capitallife
    PRIVATE include
    )

set_property(TARGET capitallife PROPERTY CXX_STANDARD 23)
    
#target_compile_options(capitallife PUBLIC -Wall -Wextra -Werror -pedantic -Wconversion -pthread -fsanitize=address,undefined)
#target_link_options(capitallife  PUBLIC -fsanitize=address,undefined)

target_link_libraries(capitallife SDL2main SDL2 SDL2_image OpenSimplexNoise)

add_custom_command(TARGET capitallife PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/res/ ${CMAKE_CURRENT_BINARY_DIR}/res/)