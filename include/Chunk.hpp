#pragma once

#include "Window.hpp"

class World;

#include "Tile.hpp"

class Chunk {
public:
    Chunk(World* p_world, unsigned char p_x, unsigned char p_y, SDL_Texture* texture);
    ~Chunk();

    void update();
    void render(Window* p_window);
private:
    World* world;
    unsigned char x;
    unsigned char y;
    Tile* tiles[16][16];
};