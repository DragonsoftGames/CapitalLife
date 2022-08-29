#pragma once

#include "Window.hpp"

class TextureManager
{
public:
    static SDL_Texture* loadTexture(const char* filePath);
};