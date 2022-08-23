#include "world/World.hpp"

#include "world/Tile.hpp"

World::World()
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

void World::update()
{

}

void World::render(Window* p_window)
{
    for (auto const& [key, chunk] : chunks)
    {
        chunk->render(p_window);
    }
}

void World::loadChunk(unsigned char p_x, unsigned char p_y)
{
    chunks[{p_x, p_y}] = new Chunk(this, p_x, p_y);
}