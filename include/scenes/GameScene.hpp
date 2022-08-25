#pragma once

#include "Scene.hpp"
#include "world/World.hpp"

class GameScene : public Scene
{
public:
    GameScene();
    ~GameScene();

    void update() override;
    void render(Window* p_window) override;
private:
    World* world;
};