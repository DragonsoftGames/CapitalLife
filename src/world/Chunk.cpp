#include "world/Chunk.hpp"

#include "world/block/BlockTypes.hpp"

Chunk::Chunk(World* p_world, unsigned char p_x, unsigned char p_y, SDL_Texture* texture)
    :world(p_world), x(p_x), y(p_y)
{
    for (int tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (int tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            tiles[tileX][tileY] = new Tile(this, tileX, tileY);
            tiles[tileX][tileY]->addBlock(new Block{&BlockTypes::grass, nullptr});
        }
    }
}

Chunk::~Chunk()
{
    for (int tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (int tileY = 0; tileY < CHUNK_SIZE; tileY++)
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
    for (int tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (int tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            tiles[tileX][tileY]->render(p_window, tileX + (x * CHUNK_SIZE), tileY + (y * CHUNK_SIZE));
        }
    }
}