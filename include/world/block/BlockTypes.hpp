#pragma once

#include "world/Block.hpp"
#include "world/block/BlockRenderers.hpp"

namespace BlockTypes {
    inline BlockType grass;

    inline void setup(Window* p_window)
    {
        grass = BlockType{"cali:grass", false, new StaticBlockRenderer(p_window->loadTexture("res/artwork/grass.png"))};
    }
}