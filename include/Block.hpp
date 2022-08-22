#pragma once

#include "Window.hpp"

class Block {
public:
    Block(SDL_Texture* p_tex, bool p_transparent);

    void render(Window* p_window, int p_x, int p_y);

    bool isTransparent();
private:
    SDL_Texture* texture;
    bool transparent;
};