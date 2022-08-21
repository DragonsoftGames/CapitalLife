#include "World.hpp"

#include "Tile.hpp"

World::World()
{

}

void World::update()
{

}

void World::render(Window* p_window)
{
    Tile tileOne(this, 0, 0, p_window->loadTexture("res/artwork/grass.png"));
    Tile tileTwo(this, 0, 1, p_window->loadTexture("res/artwork/grass.png"));
    tileOne.render(p_window);
    tileTwo.render(p_window);
}