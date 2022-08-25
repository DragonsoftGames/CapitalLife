#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window
{
public:
    Window(const char* p_title, int p_width, int p_height);

    void clear();
    void render(SDL_Texture* p_tex, SDL_Rect src, SDL_Rect dst);
    void display();

    void cleanup();

    static SDL_Renderer* renderer;
private:
    SDL_Window* window;
};