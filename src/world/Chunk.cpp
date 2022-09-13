#include "world/Chunk.hpp"

#include "world/block/BlockTypes.hpp"

#include "math/Convertions.hpp"

Chunk::Chunk(World& p_world, int p_x, int p_y)
    :world(p_world), x(p_x), y(p_y)
{
    for (unsigned char tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (unsigned char tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            tiles[tileX][tileY] = new Tile(*this, tileX, tileY);
            //if ((tileX == 0 || tileX == CHUNK_SIZE - 1) && (tileY == 0 || tileY == CHUNK_SIZE - 1))
                tiles[tileX][tileY]->addBlock(new Block{BlockTypes::grass, nullptr});
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

Tile* Chunk::getTileAt(unsigned char p_x, unsigned char p_y)
{
    return tiles[p_x][p_y];
}

void Chunk::addBlockAt(unsigned char p_x, unsigned char p_y, Block* block)
{
    tiles[p_x][p_y]->addBlock(block);
}

Block* Chunk::getBlockAt(unsigned char p_x, unsigned char p_y)
{
    return tiles[p_x][p_y]->getBlock();
}

Block* Chunk::removeBlockAt(unsigned char p_x, unsigned char p_y)
{
    return tiles[p_x][p_y]->removeBlock();
}

void Chunk::update()
{

}

void Chunk::render(Camera& p_camera)
{
    for (unsigned char tileX = 0; tileX < CHUNK_SIZE; tileX++)
    {
        for (unsigned char tileY = 0; tileY < CHUNK_SIZE; tileY++)
        {
            tiles[tileX][tileY]->render(p_camera, i32(tileX) + (x * CHUNK_SIZE), i32(tileY) + (y * CHUNK_SIZE));
        }
    }
}