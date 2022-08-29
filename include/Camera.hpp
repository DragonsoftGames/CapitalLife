#pragma once

#include "math/Vector2.hpp"
#include "Window.hpp"

class Camera
{
public:
    Camera() :offset(Vector2f::Zero) { }
    ~Camera() {}

    void render(SDL_Texture* p_texture, SDL_Rect src, SDL_Rect dst)
    {
        SDL_Rect newDst{dst.x - static_cast<int>(offset.x), dst.y - static_cast<int>(offset.y), dst.w, dst.h};
        SDL_RenderCopy(Window::renderer, p_texture, &src, &newDst);
    }

    Vector2f offset;
};