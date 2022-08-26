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
};