#pragma once
#include <deque>

#include "Window.hpp"

class Chunk;

#include "Block.hpp"

class Tile {
public:
    Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y);
    ~Tile();

    void addBlock(Block* block);
    Block* removeBlock();

    void update();
    void render(Window* p_window, int p_x, int p_y);
private:
    void calcLastRenderIndex();

    Chunk* chunk;
    unsigned char x;
    unsigned char y;
    std::deque<Block*> blockStack;
    int lastRenderIndex = -1;
};