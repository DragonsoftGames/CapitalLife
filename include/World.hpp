#pragma once

#include "Window.hpp"

#include "Chunk.hpp"

class World {
public:
    World(SDL_Texture* texture);

    void update();
    void render(Window* p_window);
private:
    Chunk chunk;
};