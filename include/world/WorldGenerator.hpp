#pragma once

#include <cstdint>
#include <OpenSimplexNoise.h>
#include "world/World.hpp"

class WorldGenerator
{
public:
    WorldGenerator(int64_t p_seed);

    void generateChunk(World &p_world, int p_x, int p_y);

private:
    int64_t seed;
    OpenSimplexNoise::Noise noise;
};