#pragma once

#include "Scene.hpp"

#include "world/World.hpp"
#include "ecs/Entity.hpp"
#include "Camera.hpp"

class GameScene : public Scene
{
public:
    GameScene();
    ~GameScene();

    void update(float p_deltaTime) override;
    void render() override;
private:
    void handlePlayerInput();
    void handleVelocity(float p_deltaTime);
    void renderSprites();

    Camera camera;
    World world;
    Entity player;
};