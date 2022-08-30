#pragma once

#include "math/Vec2.hpp"

struct AABB
{
    float x, y;
    float width, height;

    bool collides(const Vec2& offset, const AABB other, const Vec2& otherOffset) const
    {
        auto mX = x + offset.x;
        auto mY = y + offset.y;
        auto oX = other.x + otherOffset.x;
        auto oY = other.y + otherOffset.y;
        return mX < oX + other.width
            && mX + width > oX
            && mY < oY + other.height
            && mY + height > oY;
    }
};