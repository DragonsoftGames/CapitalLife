#pragma once

#include "world/Block.hpp"
#include "world/block/BlockRenderers.hpp"

namespace BlockTypes {
    static BlockType grass;

    static void setup(Window* p_window)
    {
        grass = BlockType{"cali:grass", new StaticBlockRenderer(p_window->loadTexture("res/artwork/grass.png"))};
    }
}