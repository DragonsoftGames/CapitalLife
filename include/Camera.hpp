#pragma once

#include "math/Vec2.hpp"
#include "Window.hpp"

class Camera
{
public:
    Camera(float p_scale) :offset(Vec2::Zero), scale(p_scale) { }
    ~Camera() {}

    void render(SDL_Texture* p_texture, SDL_Rect src, Vec2 pos, Vec2 size)
    {
        SDL_Rect dst{
            static_cast<int>((pos.x * scale) - std::floor(offset.x)), static_cast<int>((pos.y * scale) - std::floor(offset.y)), 
            static_cast<int>(scale * size.x), static_cast<int>(scale * size.y)};
        SDL_RenderCopy(Window::renderer, p_texture, &src, &dst);
    }

    void drawRect(float x, float y, float width, float height)
    {
        SDL_Rect rect = SDL_Rect{static_cast<int>((x * scale) - std::floor(offset.x)), static_cast<int>((y * scale) - std::floor(offset.y)), static_cast<int>(width * scale), static_cast<int>(height * scale)};
        SDL_SetRenderDrawColor(Window::renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(Window::renderer, &rect);
    }

    Vec2 offset;
    float scale;
};