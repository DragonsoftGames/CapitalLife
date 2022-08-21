#include "Tile.hpp"

Tile::Tile(World* p_world, unsigned char p_x, unsigned char p_y, SDL_Texture* p_tex)
    :world(p_world), x(p_x), y(p_y), texture(p_tex)
{

}

void Tile::update()
{

}

void Tile::render(Window* p_window)
{
    p_window->render(texture, {0, 0, 32, 32}, {64*x, 64*y, 64, 64});
}