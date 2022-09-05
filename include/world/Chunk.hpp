#pragma once

#define CHUNK_SIZE 8

class World;

#include "world/Tile.hpp"

class Chunk
{
public:
    Chunk(World& p_world, int p_x, int p_y);
    ~Chunk();

    Tile* getTileAt(int p_x, int p_y);
    void addBlockAt(int p_x, int p_y, Block* block);
    Block* getBlockAt(int p_x, int p_y);
    Block* removeBlockAt(int p_x, int p_y);

    void update();
    void render(Camera& p_camera);
private:
    World& world;
    int x;
    int y;
    Tile* tiles[CHUNK_SIZE][CHUNK_SIZE];
};