#include "Chunk.hpp"

Chunk::Chunk(World* p_world, unsigned char p_x, unsigned char p_y, SDL_Texture* texture)
    :world(p_world), x(p_x), y(p_y)
{
    for (int tileX = 0; tileX < 16; tileX++)
    {
        for (int tileY = 0; tileY < 16; tileY++)
        {
            tiles[tileX][tileY] = new Tile(this, tileX, tileY, texture);
        }
    }
}

Chunk::~Chunk()
{
    for (int tileX = 0; tileX < 16; tileX++)
    {
        for (int tileY = 0; tileY < 16; tileY++)
        {
            delete tiles[tileX][tileY];
        }
    }
}

void Chunk::update()
{

}

void Chunk::render(Window* p_window)
{
    for (int tileX = 0; tileX < 16; tileX++)
    {
        for (int tileY = 0; tileY < 16; tileY++)
        {
            tiles[tileX][tileY]->render(p_window, tileX + (x * 16), tileY + (y * 16));
        }
    }
}