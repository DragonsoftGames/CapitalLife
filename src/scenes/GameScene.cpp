#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"

#include "ecs/Components.hpp"

GameScene::GameScene()
    :world(World()), player(createEntity())
{
    world.addBlockAt(0, 0, new Block{BlockTypes::grass, nullptr});
    player.addComponent<TransformComponent>(Vector2f{0.0f, 0.0f});
}

GameScene::~GameScene()
{

}

void GameScene::update()
{

}

void GameScene::render(Window* p_window)
{
    world.render(p_window);
}