#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"

#include "ecs/Components.hpp"

#include "TextureManager.hpp"

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

void GameScene::update()
{

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