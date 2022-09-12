#include "world/World.hpp"

#include "world/block/BlockTypes.hpp"

#include "world/Tile.hpp"

#include "math/Convertions.hpp"

World::World()
    :chunks(ChunkMap())
{
}

World::~World()
{
    for (auto const& [key, chunk] : chunks)
    {
        delete chunk;
    }
    chunks.clear();
}

Tile* World::getTileAt(int p_x, int p_y)
{
    auto cX = i32(std::floor(f32(p_x < 0 ? p_x - 1 : p_x) / CHUNK_SIZE));
    auto cY = i32(std::floor(f32(p_y < 0 ? p_y - 1 : p_y) / CHUNK_SIZE));
    auto tX = p_x % CHUNK_SIZE;
    if (tX < 0) { tX = tX + CHUNK_SIZE; } 
    auto tY = p_y % CHUNK_SIZE;
    if (tY < 0) { tY = tY + CHUNK_SIZE; } 

    if (!chunks.contains(std::make_pair(cX, cY)))
    {
        //loadChunk(cX, cY);
    }
    Chunk* chunk = chunks[std::make_pair(cX, cY)];
    return chunk->getTileAt(i32(tX), i32(tY));
}

void World::addBlockAt(int p_x, int p_y, Block* p_block)
{
    getTileAt(p_x, p_y)->addBlock(p_block);
}

Block* World::getBlockAt(int p_x, int p_y)
{
    return getTileAt(p_x, p_y)->getBlock();
}

Block* World::removeBlockAt(int p_x, int p_y)
{
    return getTileAt(p_x, p_y)->removeBlock();
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

void World::tryLoadChunk(int p_x, int p_y)
{
    if (chunks.contains(std::make_pair(p_x, p_y))) return;
    loadChunk(p_x, p_y);
}

void World::loadChunk(int p_x, int p_y)
{
    chunks[std::make_pair(p_x, p_y)] = new Chunk(*this, p_x, p_y);
}