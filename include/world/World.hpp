#pragma once

#include <map>

#include "world/Chunk.hpp"

class World
{
public:
    World();
    ~World();

    Tile* getTileAt(int p_x, int p_y);
    void addBlockAt(int p_x, int p_y, Block* p_block);
    Block* getBlockAt(int p_x, int p_y);
    Block* removeBlockAt(int p_x, int p_y);

    void update();
    void render(Camera& p_camera);
private:
    void loadChunk(unsigned char p_x, unsigned char p_y);
    std::map<std::pair<unsigned char, unsigned char>, Chunk*> chunks;
};