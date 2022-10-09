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
    Vec2 _delta;
    float speed;
    float acceleration;
    float friction;

    VelocityComponent(float p_speed, float p_acceleration, float p_friction) : _delta(Vec2::Zero), speed(p_speed), acceleration(p_acceleration), friction(p_friction) {}
};

struct CollisionComponent
{
    AABB box;
};