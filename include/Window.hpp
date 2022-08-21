#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window
{
public:
    Window(const char* p_title, int p_width, int p_height);
    void cleanup();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};