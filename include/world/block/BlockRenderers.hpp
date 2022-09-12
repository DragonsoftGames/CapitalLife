#pragma once

#include "world/Block.hpp"
#include "math/Vec2.hpp"

class StaticBlockRenderer : public BlockRenderer
{
public:
    StaticBlockRenderer(SDL_Texture* p_tex) :texture(p_tex) {}
    ~StaticBlockRenderer()
    {
        SDL_DestroyTexture(texture);
    }

    void render(Camera& p_camera, int p_x, int p_y)
    {
        p_camera.render(texture, {0, 0, 32, 32}, Vec2{DEFAULT_BLOCK_SIZE*p_x, DEFAULT_BLOCK_SIZE*p_y}, Vec2{DEFAULT_BLOCK_SIZE, DEFAULT_BLOCK_SIZE});
    }
private:
    SDL_Texture* texture;
};