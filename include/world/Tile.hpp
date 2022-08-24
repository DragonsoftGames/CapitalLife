#pragma once
#include <deque>

#include "Window.hpp"

class Chunk;

#include "world/Block.hpp"

class Tile
{
public:
    Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y);
    ~Tile();

    void addBlock(Block* block);
    void addBlockUnsafe(Block* block);
    Block* getBlock();
    Block* removeBlock();
    void calcFirstRenderIndex();

    void update();
    void render(Window* p_window, int p_x, int p_y);
private:

    Chunk* chunk;
    unsigned char x;
    unsigned char y;
    std::deque<Block*> blockStack;
    int firstRenderIndex = -1;
};