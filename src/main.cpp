#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Window.hpp"

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "Couldn't init SDL_Video: " << SDL_GetError() << std::endl;
        return 1;
    }
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cerr << "Couldn't init IMG_png: " << SDL_GetError() << std::endl;
        return 1;
    }

    Window window("CapitalLife", 1280, 720);

    window.cleanup();
    SDL_Quit();

    return 0;
}