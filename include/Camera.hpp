#pragma once

#include "math/Vec2.hpp"
#include "Window.hpp"
#include "math/Convertions.hpp"

class Camera
{
public:
    Camera(float p_scale) : offset(Vec2::Zero), scale(p_scale) {}
    ~Camera() {}

    void render(SDL_Texture *p_texture, SDL_Rect src, Vec2 pos, Vec2 size)
    {
        SDL_Rect dst{
            i32(std::floor(pos.x * scale - offset.x)), i32(std::floor(pos.y * scale - offset.y)),
            i32(scale * size.x), i32(scale * size.y)};
        SDL_RenderCopy(Window::renderer, p_texture, &src, &dst);
    }

    void drawRect(float x, float y, float width, float height)
    {
        SDL_Rect rect = SDL_Rect{
            i32(std::floor(x * scale - offset.x)), i32(std::floor(y * scale - offset.y)),
            i32(width * scale), i32(height * scale)};
        SDL_SetRenderDrawColor(Window::renderer, 255, 0, 0, 255);
        SDL_RenderDrawRect(Window::renderer, &rect);
    }

    Vec2 offset;
    float scale;
};