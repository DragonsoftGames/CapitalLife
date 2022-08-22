#include "Tile.hpp"

Tile::Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y, SDL_Texture* p_tex)
    :chunk(p_chunk), x(p_x), y(p_y), texture(p_tex)
{

}

Tile::~Tile()
{
    
}

void Tile::update()
{

}

void Tile::render(Window* p_window, int p_x, int p_y)
{
    p_window->render(texture, {0, 0, 32, 32}, {64*p_x, 64*p_y, 64, 64});
}