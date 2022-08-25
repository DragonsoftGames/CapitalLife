#include "world/Chunk.hpp"

#include "world/block/BlockTypes.hpp"

Chunk::Chunk(World& p_world, unsigned char p_x, unsigned char p_y)
    :world(p_world), x(p_x), y(p_y)
{
    for (unsigned char tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (unsigned char tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            tiles[tileX][tileY] = new Tile(*this, tileX, tileY);
        }
    }
}

Chunk::~Chunk()
{
    for (unsigned char tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (unsigned char tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            delete tiles[tileX][tileY];
        }
    }
}

void Chunk::addBlockAt(int p_x, int p_y, Block* block)
{
    tiles[p_x][p_y]->addBlock(block);
}

Block* Chunk::getBlockAt(int p_x, int p_y)
{
    return tiles[p_x][p_y]->getBlock();
}

Block* Chunk::removeBlockAt(int p_x, int p_y)
{
    return tiles[p_x][p_y]->removeBlock();
}

void Chunk::update()
{

}

void Chunk::render(Window* p_window)
{
    for (unsigned char tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (unsigned char tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            tiles[tileX][tileY]->render(p_window, tileX + (x * CHUNK_SIZE), tileY + (y * CHUNK_SIZE));
        }
    }
}