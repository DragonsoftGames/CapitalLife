#pragma once

#define CHUNK_SIZE 8

#include "Window.hpp"

class World;

#include "world/Tile.hpp"

class Chunk
{
public:
    Chunk(World* p_world, unsigned char p_x, unsigned char p_y);
    ~Chunk();

    void addBlockAt(int p_x, int p_y, Block* block);
    Block* getBlockAt(int p_x, int p_y);
    Block* removeBlockAt(int p_x, int p_y);

    void update();
    void render(Window* p_window);
private:
    World* world;
    unsigned char x;
    unsigned char y;
    Tile* tiles[CHUNK_SIZE][CHUNK_SIZE];
};