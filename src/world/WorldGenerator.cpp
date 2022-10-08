#include "world/WorldGenerator.hpp"
#include <iostream>
#include "math/Convertions.hpp"
#include "world/block/BlockTypes.hpp"

WorldGenerator::WorldGenerator(int64_t p_seed)
    : seed(p_seed), noise(OpenSimplexNoise::Noise(p_seed))
{
}

void WorldGenerator::generateChunk(World &p_world, int p_x, int p_y)
{
    auto chunk = new Chunk(p_world, p_x, p_y);
    for (unsigned char x = 0; x < CHUNK_SIZE; x++)
    {
        for (unsigned char y = 0; y < CHUNK_SIZE; y++)
        {
            auto *tile = chunk->getTileAt(x, y);
            auto n = noise.eval(f64(p_x * CHUNK_SIZE + x) / 23.0, f64(p_y * CHUNK_SIZE + y) / 23.0);
            if (n < 0.21)
            {
                tile->addBlock(new Block{BlockTypes::grass, nullptr});
            }
        }
    }
    p_world.chunks[std::make_pair(p_x, p_y)] = chunk;
}