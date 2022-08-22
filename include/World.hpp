#pragma once

#include <map>
#include "Window.hpp"

#include "Chunk.hpp"

class World {
public:
    World(SDL_Texture* texture);
    ~World();

    void update();
    void render(Window* p_window);
private:
    void loadChunk(unsigned char p_x, unsigned char p_y, SDL_Texture* texture);
    std::map<std::pair<unsigned char, unsigned char>, Chunk*> chunks;
};