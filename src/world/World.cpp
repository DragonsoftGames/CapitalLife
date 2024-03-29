#include "world/World.hpp"

#include "world/block/BlockTypes.hpp"

#include "world/Tile.hpp"

World::World()
    :chunks(std::map<std::pair<unsigned char, unsigned char>, Chunk*>())
{
    loadChunk(0, 0);
    loadChunk(1, 0);
}

World::~World()
{
    for (auto const& [key, chunk] : chunks)
    {
        delete chunk;
    }
    chunks.clear();
}

void World::addBlockAt(int p_x, int p_y, Block* p_block)
{
    auto x = std::div(p_x, CHUNK_SIZE);
    auto y = std::div(p_y, CHUNK_SIZE);
    Chunk* chunk = chunks[{x.quot, y.quot}];
    chunk->addBlockAt(x.rem, y.rem, p_block);
}

Block* World::getBlockAt(int p_x, int p_y)
{
    auto x = std::div(p_x, CHUNK_SIZE);
    auto y = std::div(p_y, CHUNK_SIZE);
    Chunk* chunk = chunks[{x.quot, y.quot}];
    return chunk->getBlockAt(x.rem, y.rem);
}

Block* World::removeBlockAt(int p_x, int p_y)
{
    auto x = std::div(p_x, CHUNK_SIZE);
    auto y = std::div(p_y, CHUNK_SIZE);
    Chunk* chunk = chunks[{x.quot, y.quot}];
    return chunk->removeBlockAt(x.rem, y.rem);
}

void World::update()
{

}

void World::render(Camera& p_camera)
{
    for (auto const& [key, chunk] : chunks)
    {
        chunk->render(p_camera);
    }
}

void World::loadChunk(unsigned char p_x, unsigned char p_y)
{
    chunks[{p_x, p_y}] = new Chunk(*this, p_x, p_y);
}