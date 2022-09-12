#pragma once

#include <map>

#include "world/Chunk.hpp"

typedef std::map<std::pair<int, int>, Chunk*> ChunkMap;

class World
{
public:
    World();
    ~World();

    void tryLoadChunk(int p_x, int p_y);
    void loadChunk(int p_x, int p_y);
    
    Tile* getTileAt(int p_x, int p_y);
    void addBlockAt(int p_x, int p_y, Block* p_block);
    Block* getBlockAt(int p_x, int p_y);
    Block* removeBlockAt(int p_x, int p_y);

    void update();
    void render(Camera& p_camera);

    ChunkMap chunks;
private:
};