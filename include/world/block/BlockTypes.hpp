#pragma once

#include "world/Block.hpp"
#include "world/block/BlockRenderers.hpp"
#include "TextureManager.hpp"

namespace BlockTypes
{
    inline BlockType* grass;

    inline void setup()
    {
        grass = new BlockType{"cali:grass", false, new StaticBlockRenderer(TextureManager::loadTexture("res/artwork/grass_new.png"))};
    }

    inline void cleanup()
    {
        delete grass;
    }
}