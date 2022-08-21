#include "World.hpp"

#include "Tile.hpp"

World::World(SDL_Texture* texture)
    :chunk(this, 0, 0, texture)
{

}

void World::update()
{

}

void World::render(Window* p_window)
{
    chunk.render(p_window);
}