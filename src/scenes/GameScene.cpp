#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"

GameScene::GameScene()
    :world(World())
{
    world.addBlockAt(0, 0, new Block{BlockTypes::grass, nullptr});
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