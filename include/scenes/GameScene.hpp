#pragma once

#include "Scene.hpp"

#include "world/World.hpp"
#include "world/WorldGenerator.hpp"
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
    void moveCamera(float p_deltaTime);
    void loadNearbyWorld();

    void renderSprites();

    World world;
    WorldGenerator worldGen;
    Entity player;
    Camera camera;
};