#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Window.hpp"
#include "scenes/GameScene.hpp"
#include "world/block/BlockTypes.hpp"
#include "inventory/item/ItemTypes.hpp"
#include "Input.hpp"

int main()
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

    BlockTypes::setup();
    ItemTypes::setup();

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 currentTime = 0;
    Uint32 lastTime = 0;
    float deltaTime = 0;

    {
        Scene *scene = new GameScene();

        bool gameRunning = true;

        SDL_Event event;
        while (gameRunning)
        {
            currentTime = SDL_GetTicks();
            int frameTime = currentTime - lastTime;
            deltaTime = ((float)frameTime) / 1000.0f;
            if (frameDelay > frameTime)
            {
                SDL_Delay(frameDelay - frameTime);
            }
            lastTime = currentTime;

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    gameRunning = false;
            }

            window.clear();

            Input::update();

            scene->update(deltaTime);
            scene->render();

            window.display();
        }

        delete scene;
    }

    ItemTypes::cleanup();
    BlockTypes::cleanup();

    window.cleanup();
    SDL_Quit();

    return 0;
}