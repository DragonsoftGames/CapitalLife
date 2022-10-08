#pragma once

#define CHUNK_SIZE 8

class World;

#include "world/Tile.hpp"

class Chunk
{
public:
    Chunk(World &p_world, int p_x, int p_y);
    ~Chunk();

    Tile *getTileAt(unsigned char p_x, unsigned char p_y);
    void addBlockAt(unsigned char p_x, unsigned char p_y, Block *block);
    Block *getBlockAt(unsigned char p_x, unsigned char p_y);
    Block *removeBlockAt(unsigned char p_x, unsigned char p_y);

    void update();
    void render(Camera &p_camera);

    const int x;
    const int y;

private:
    World &world;
    Tile *tiles[CHUNK_SIZE][CHUNK_SIZE];
};