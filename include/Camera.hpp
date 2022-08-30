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
        SDL_Rect newDst{dst.x - static_cast<int>(std::floor(offset.x)), dst.y - static_cast<int>(std::floor(offset.y)), dst.w, dst.h};
        SDL_RenderCopy(Window::renderer, p_texture, &src, &newDst);
    }

    void drawRect(float x, float y, float width, float height)
    {
        SDL_Rect rect = SDL_Rect{static_cast<int>(x - std::floor(offset.x)), static_cast<int>(y - std::floor(offset.y)), static_cast<int>(width), static_cast<int>(height)};
        SDL_RenderDrawRect(Window::renderer, &rect);
    }

    Vector2f offset;
};