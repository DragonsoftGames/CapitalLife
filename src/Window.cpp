#include "Window.hpp"

#include <iostream>

Window::Window(const char* p_title, int p_width, int p_height)
    :window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, p_width, p_height, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cerr << "Window failed to init: " << SDL_GetError() << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* Window::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
    {
        std::cerr << "Failed to load texture: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void Window::clear()
{
    SDL_RenderClear(renderer);
}

void Window::render(SDL_Texture* p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = 64;
    dst.h = 64;

    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void Window::display()
{
    SDL_RenderPresent(renderer);
}

void Window::cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}