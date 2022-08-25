#pragma once

#include "math/Vector2.hpp"
#include "Window.hpp"

struct TransformComponent
{
    Vector2f pos;
    Vector2f size;
};

struct SpriteComponent
{
    SDL_Texture* texture;

    void render(Window* p_window, TransformComponent& p_transform)
    {
        auto src = SDL_Rect{0, 0, 32, 32};
        auto dst = SDL_Rect{static_cast<int>(p_transform.pos.x), static_cast<int>(p_transform.pos.y), static_cast<int>(p_transform.size.x)*16, static_cast<int>(p_transform.size.y)*16};
        p_window->render(texture, src, dst);
    }
};