#pragma once

#include "math/Vec2.hpp"
#include "Window.hpp"
#include "math/AABB.hpp"

struct TransformComponent
{
    Vec2 pos;
    Vec2 size;
};

struct SpriteComponent
{
    SDL_Texture *texture;
};

struct VelocityComponent
{
    Vec2 delta;
    float speed;

    VelocityComponent(float p_speed) : delta(Vec2::Zero), speed(p_speed) {}
};

struct CollisionComponent
{
    AABB box;
};