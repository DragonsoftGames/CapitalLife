#include "World.hpp"

#include "Tile.hpp"

World::World(SDL_Texture* texture)
{
    loadChunk(0, 0, texture);
    loadChunk(1, 0, texture);
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

void World::loadChunk(unsigned char p_x, unsigned char p_y, SDL_Texture* texture)
{
    chunks[{p_x, p_y}] = new Chunk(this, p_x, p_y, texture);
}