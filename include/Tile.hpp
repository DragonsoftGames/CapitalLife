#pragma once

#include "World.hpp"

class Tile {
public:
    Tile(World* p_world, unsigned char p_x, unsigned char p_y, SDL_Texture* p_tex);
    
    void update();
    void render(Window* p_window);
private:
    World* world;
    unsigned char x;
    unsigned char y;
    SDL_Texture* texture;
};