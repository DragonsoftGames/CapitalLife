#pragma once

#include "math/Vector2.hpp"
#include "Window.hpp"
#include "math/AABB.hpp"

struct TransformComponent
{
    Vector2f pos;
    Vector2f size;
};

struct SpriteComponent
{
    SDL_Texture* texture;
};

struct VelocityComponent
{
    Vector2f delta;
    float speed;

    VelocityComponent(float p_speed) :delta(Vector2f::Zero), speed(p_speed) { }
};

struct CollisionComponent
{
    AABB box;
};