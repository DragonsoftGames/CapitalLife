#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"

#include "ecs/Components.hpp"

#include "TextureManager.hpp"

#include <iostream>

GameScene::GameScene()
    :world(World()), player(createEntity())
{
    world.addBlockAt(0, 0, new Block{BlockTypes::grass, nullptr});
    player.addComponent<TransformComponent>(Vector2f{50.0f, 37.0f}, Vector2f{3.0f, 3.0f});
    player.addComponent<SpriteComponent>(TextureManager::loadTexture("res/artwork/grass.png"));
}

GameScene::~GameScene()
{
    player.destroy();
}

void GameScene::update(float deltaTime)
{
    const Uint8* keys = SDL_GetKeyboardState(nullptr);
    { // Player Movement
        Vector2f velocity = Vector2f::Zero;
        if(keys[SDL_SCANCODE_W])
        {
            velocity.y -= 1.0f;
        }
        if(keys[SDL_SCANCODE_A])
        {
            velocity.x -= 1.0f;
        }
        if(keys[SDL_SCANCODE_S])
        {
            velocity.y += 1.0f;
        }
        if(keys[SDL_SCANCODE_D])
        {
            velocity.x += 1.0f;
        }
        velocity.Normalize();
        player.getComponent<TransformComponent>().pos += velocity * deltaTime * 200.0f;
    }
}

void GameScene::render(Window* p_window)
{
    world.render(p_window);
    auto renderView = registry.view<TransformComponent, SpriteComponent>();
    for (auto [entity, transform, sprite]: renderView.each())
    {
        sprite.render(p_window, transform);
    }
}