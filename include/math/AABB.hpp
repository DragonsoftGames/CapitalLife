#pragma once

struct AABB
{
    float x, y;
    float width, height;

    bool collides(AABB other)
    {
        return x < other.x + other.width
            && x + width > other.x
            && y < other.y + other.height
            && y + height > other.y;
    }
};