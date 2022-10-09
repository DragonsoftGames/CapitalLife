#pragma once

#include <SDL2/SDL.h>
#include "math/Vec2.hpp"

// TODO: Make them changeable ingame
#define CALI_INPUT_KEY_FORWARD SDL_SCANCODE_W
#define CALI_INPUT_KEY_BACK SDL_SCANCODE_S
#define CALI_INPUT_KEY_LEFT SDL_SCANCODE_A
#define CALI_INPUT_KEY_RIGHT SDL_SCANCODE_D

class Input
{
public:
    static void update()
    {
        keys = SDL_GetKeyboardState(nullptr);
    }

    static Vec2 getInputDirection();

    static bool isKeyPressed(SDL_Scancode key);

private:
    inline static const Uint8 *keys = nullptr;
};