#include "TextureManager.hpp"

#include <iostream>

SDL_Texture* TextureManager::loadTexture(const char* filePath)
{
    SDL_Surface* tempSurface = IMG_Load(filePath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    if (texture == NULL)
    {
        std::cerr << "Failed to load texture: " << SDL_GetError() << std::endl;
    }

    return texture;
}