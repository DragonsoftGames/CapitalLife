#pragma once
#include <deque>

#include "Camera.hpp"

class Chunk;

#include "world/Block.hpp"

class Tile
{
public:
    Tile(Chunk& p_chunk, unsigned char p_x, unsigned char p_y);
    ~Tile();

    void addBlock(Block* block);
    void addBlockUnsafe(Block* block);
    Block* getBlock();
    Block* removeBlock();
    void calcFirstRenderIndex();

    void update();
    void render(Camera& p_camera, int p_x, int p_y);
private:

    Chunk& chunk;
    unsigned char x;
    unsigned char y;
    std::deque<Block*> blockStack;
    std::deque<Block*>::size_type firstRenderIndex = 0;
};