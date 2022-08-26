#pragma once

#include "Scene.hpp"

#include "world/World.hpp"
#include "ecs/Entity.hpp"

class GameScene : public Scene
{
public:
    GameScene();
    ~GameScene();

    void update(float p_deltaTime) override;
    void render(Window* p_window) override;
private:
    void handlePlayerInput();
    void handleVelocity(float p_deltaTime);
    void renderSprites(Window* p_window);

    World world;
    Entity player;
};