#pragma once
#include <deque>

#include "ecs/Entity.hpp"
#include "math/AABB.hpp"
#include "Camera.hpp"

class Chunk;

#include "world/Block.hpp"

class Tile
{
public:
    Tile(Chunk &p_chunk, unsigned char p_x, unsigned char p_y);
    ~Tile();

    void addBlock(Block *block);
    void addBlockUnsafe(Block *block);
    Block *getBlock();
    Block *removeBlock();
    void calcFirstRenderIndex();

    AABB *collision(entt::entity &p_entity);

    void update();
    void render(Camera &p_camera, int p_x, int p_y);

    const Chunk &chunk;
    const unsigned char x;
    const unsigned char y;

private:
    std::deque<Block *> blockStack;
    std::deque<Block *>::size_type firstRenderIndex = 0;
};