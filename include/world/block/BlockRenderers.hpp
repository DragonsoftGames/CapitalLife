#pragma once

#include "world/Block.hpp"

class StaticBlockRenderer : public BlockRenderer {
public:
    StaticBlockRenderer(SDL_Texture* p_tex) :texture(p_tex) {}
    ~StaticBlockRenderer()
    {
        delete texture;
    }

    void render(Window* p_window, int p_x, int p_y)
    {
        p_window->render(texture, {0, 0, 32, 32}, {DEFAULT_BLOCK_SIZE*p_x, DEFAULT_BLOCK_SIZE*p_y, DEFAULT_BLOCK_SIZE - 1, DEFAULT_BLOCK_SIZE - 1});
    }
private:
    SDL_Texture* texture;
};