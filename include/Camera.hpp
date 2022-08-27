#pragma once

#include "math/Vector2.hpp"
#include "Window.hpp"

class Camera
{
public:
    Camera() :offset(Vector2i::Zero) { }
    ~Camera() {}

    void render(SDL_Texture* p_texture, SDL_Rect src, SDL_Rect dst)
    {
        SDL_Rect newDst{dst.x - offset.x, dst.y - offset.y, dst.w, dst.h};
        SDL_RenderCopy(Window::renderer, p_texture, &src, &newDst);
    }

    Vector2i offset;
};