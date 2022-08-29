#pragma once

#include <SDL2/SDL.h>

class Input
{
public:
    static void update()
    {
        keys = SDL_GetKeyboardState(nullptr);
    }

    static bool isKeyPressed(SDL_Scancode key);
private:
    inline static const Uint8* keys = nullptr;
};