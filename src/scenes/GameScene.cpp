#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"
#include "ecs/Components.hpp"
#include "TextureManager.hpp"
#include "math/AABB.hpp"
#include "Input.hpp"

#define pos(entity) entity.getComponent<TransformComponent>().pos

GameScene::GameScene()
    :world(World()), player(createEntity()), camera(Camera(16))
{
    world.addBlockAt(0, 0, new Block{BlockTypes::grass, nullptr});
    world.addBlockAt(2, 3, new Block{BlockTypes::grass, nullptr});
    player.addComponent<TransformComponent>(Vec2{-4.0f, 3.0f}, Vec2{3.0f, 3.0f});
    player.addComponent<VelocityComponent>(13.0f);
    player.addComponent<SpriteComponent>(TextureManager::loadTexture("res/artwork/grass.png"));
    player.addComponent<CollisionComponent>(AABB{0.625f, 2.0f, 1.75f, 0.625f});
}

GameScene::~GameScene()
{
    player.destroy();
}

void GameScene::update(float p_deltaTime)
{
    handlePlayerInput();
    handleVelocity(p_deltaTime);

    moveCamera(p_deltaTime);
}

void GameScene::render()
{
    world.render(camera);
    renderSprites();

    // draw collision box
    auto renderView = registry.view<TransformComponent, CollisionComponent>();
    for (auto [entity, transform, collision]: renderView.each())
    {
        camera.drawRect(collision.box.x + transform.pos.x, collision.box.y + transform.pos.y, collision.box.width, collision.box.height);
    }
}

void GameScene::handlePlayerInput()
{
    Vec2 velocity = Vec2::Zero;
    if(Input::isKeyPressed(SDL_SCANCODE_W))
    {
        velocity.y -= 1.0f;
    }
    if(Input::isKeyPressed(SDL_SCANCODE_A))
    {
        velocity.x -= 1.0f;
    }
    if(Input::isKeyPressed(SDL_SCANCODE_S))
    {
        velocity.y += 1.0f;
    }
    if(Input::isKeyPressed(SDL_SCANCODE_D))
    {
        velocity.x += 1.0f;
    }
    player.getComponent<VelocityComponent>().delta = velocity;
}

#include <iostream>

void GameScene::handleVelocity(float p_deltaTime)
{
    static auto wall = AABB{0, 0, 3, 3};

    auto renderView = registry.view<VelocityComponent, TransformComponent, CollisionComponent>();
    for (auto [entity, velocity, transform, collision]: renderView.each())
    {
        if (velocity.delta == Vec2::Zero) continue;
        velocity.delta.normalize();

        // from here on goes shitty implemented collision :)
        auto newPos = transform.pos + velocity.delta * p_deltaTime * velocity.speed;

        int leftTile = (newPos.x + collision.box.x) / DEFAULT_BLOCK_SIZE;
        int rightTile = (newPos.x + collision.box.x + collision.box.width) / DEFAULT_BLOCK_SIZE;
        int topTile = (newPos.y + collision.box.y) / DEFAULT_BLOCK_SIZE;
        int bottomTile = (newPos.y + collision.box.y + collision.box.height) / DEFAULT_BLOCK_SIZE;

        for (int tileX = leftTile; tileX <= rightTile; tileX++)
        {
            for (int tileY = topTile; tileY <= bottomTile; tileY++)
            {
                auto tileCol = world.getTileAt(tileX, tileY)->collision(entity);
                if (tileCol == nullptr) continue;
                auto scaledX = tileX * DEFAULT_BLOCK_SIZE;
                auto scaledY = tileY * DEFAULT_BLOCK_SIZE;
                
                if (tileCol->collides(Vec2{scaledX, scaledY}, collision.box, Vec2{newPos.x, transform.pos.y}))
                {
                    auto leftSide = tileCol->x + scaledX;
                    if (transform.pos.x < leftSide)
                    {
                        newPos.x = leftSide - collision.box.x - collision.box.width;
                    }
                    else
                    {
                        auto rightSide = leftSide + tileCol->width;
                        newPos.x = rightSide - collision.box.x;
                    }
                }
                if (tileCol->collides(Vec2{scaledX, scaledY}, collision.box, Vec2{transform.pos.x, newPos.y}))
                {
                    auto topSide = tileCol->y + scaledY;
                    if (transform.pos.y < topSide)
                    {
                        newPos.y = topSide - collision.box.y - collision.box.height;
                    }
                    else
                    {
                        auto bottomSide = topSide + tileCol->height;
                        newPos.y = bottomSide - collision.box.y;
                    }
                }
            }
        }

        transform.pos.x = newPos.x;
        transform.pos.y = newPos.y;
    }
}

void GameScene::moveCamera(float p_deltaTime)
{
    static float smoothSpeed = 4.0f;

    auto& transform = player.getComponent<TransformComponent>();
    int w, h;
    SDL_GetRendererOutputSize(Window::renderer, &w, &h);
    Vec2 offset = Vec2{(transform.pos.x * camera.scale) - w / 2 + (transform.size.x * camera.scale) / 2, (transform.pos.y * camera.scale) - h / 2 + (transform.size.y * camera.scale) / 2};
    camera.offset.lerp(offset, smoothSpeed * p_deltaTime);
}

void GameScene::renderSprites()
{
    auto renderView = registry.view<SpriteComponent, TransformComponent>();
    for (auto [entity, sprite, transform]: renderView.each())
    {
        auto src = SDL_Rect{0, 0, 32, 32};
        camera.render(sprite.texture, src, Vec2{transform.pos.x, transform.pos.y}, Vec2{transform.size.x, transform.size.y});
    }
}