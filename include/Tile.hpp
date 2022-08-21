#pragma once

#include "Window.hpp"

class Chunk;

class Tile {
public:
    Tile(Chunk* p_chunk, unsigned char p_x, unsigned char p_y, SDL_Texture* p_tex);
    
    void update();
    void render(Window* p_window);
private:
    Chunk* chunk;
    unsigned char x;
    unsigned char y;
    SDL_Texture* texture;
};