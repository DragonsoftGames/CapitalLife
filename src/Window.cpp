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

void Window::cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}