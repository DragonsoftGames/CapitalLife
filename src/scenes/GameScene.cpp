#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"
#include "ecs/Components.hpp"
#include "TextureManager.hpp"
#include "math/AABB.hpp"
#include "Input.hpp"

GameScene::GameScene()
    :world(World()), player(createEntity()), camera(Camera())
{
    world.addBlockAt(0, 0, new Block{BlockTypes::grass, nullptr});
    world.addBlockAt(2, 3, new Block{BlockTypes::grass, nullptr});
    player.addComponent<TransformComponent>(Vector2f{50.0f, 37.0f}, Vector2f{3.0f, 3.0f});
    player.addComponent<VelocityComponent>(200.0f);
    player.addComponent<SpriteComponent>(TextureManager::loadTexture("res/artwork/grass.png"));
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
}

void GameScene::handlePlayerInput()
{
    Vector2f velocity = Vector2f::Zero;
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

void GameScene::handleVelocity(float p_deltaTime)
{
    static auto wall = AABB{0, 0, 48, 48};

    auto renderView = registry.view<VelocityComponent, TransformComponent>();
    for (auto [entity, velocity, transform]: renderView.each())
    {
        if (velocity.delta == Vector2f::Zero) continue;
        velocity.delta.normalize();
        // from here on goes shitty implemented collision :)
        auto newPos = transform.pos + velocity.delta * p_deltaTime * velocity.speed;
        auto size = transform.size * 16;
        if (wall.collides(AABB{newPos.x, transform.pos.y, size.x, size.y}))
        {
            // TODO: maybe calculate path to get out exactly at edge?
        } else
        {
            transform.pos.x = newPos.x;
        }
        if (wall.collides(AABB{transform.pos.x, newPos.y, size.x, size.y}))
        {
            // TODO: maybe calculate path to get out exactly at edge?
        } else
        {
            transform.pos.y = newPos.y;
        }
    }
}

void GameScene::moveCamera(float p_deltaTime)
{
    static float smoothSpeed = 4.0f;

    auto& transform = player.getComponent<TransformComponent>();
    int w, h;
    SDL_GetRendererOutputSize(Window::renderer, &w, &h);
    Vector2f offset = Vector2f{transform.pos.x - w / 2 + (transform.size.x * 16) / 2, transform.pos.y - h / 2 + (transform.size.y * 16) / 2};
    camera.offset.lerp(offset, smoothSpeed * p_deltaTime);
}

void GameScene::renderSprites()
{
    auto renderView = registry.view<SpriteComponent, TransformComponent>();
    for (auto [entity, sprite, transform]: renderView.each())
    {
        auto src = SDL_Rect{0, 0, 32, 32};
        auto dst = SDL_Rect{static_cast<int>(transform.pos.x), static_cast<int>(transform.pos.y), static_cast<int>(transform.size.x)*16, static_cast<int>(transform.size.y)*16};
        camera.render(sprite.texture, src, dst);
    }
}