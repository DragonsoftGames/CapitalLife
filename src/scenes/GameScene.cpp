#include "scenes/GameScene.hpp"

#include "world/block/BlockTypes.hpp"
#include "ecs/Components.hpp"
#include "TextureManager.hpp"
#include "math/AABB.hpp"
#include "Input.hpp"
#include "math/Convertions.hpp"
#include "inventory/PlayerInventory.hpp"
#include "inventory/Inventory.hpp"
#include "inventory/item/ItemTypes.hpp"

#define trans(entity) entity.getComponent<TransformComponent>()

GameScene::GameScene()
    : world(World()), worldGen(WorldGenerator(13)), player(createEntity()), camera(Camera(16))
{
    player.addComponent<TransformComponent>(Vec2{-4.0f, 3.0f}, Vec2{3.0f, 3.0f});
    player.addComponent<VelocityComponent>(13.0f, 2.0f, 4.5f);
    player.addComponent<SpriteComponent>(TextureManager::loadTexture("res/artwork/grass.png"));
    player.addComponent<CollisionComponent>(AABB{0.625f, 2.0f, 1.75f, 0.625f});
    player.addComponent<PlayerInventory>();
    player.addComponent<Inventory>(12);

    {
        player.getComponent<Inventory>().addItem(Item(ItemTypes::stick, nullptr));
        player.getComponent<Inventory>().addItem(Item(ItemTypes::stick, nullptr));
    }
    auto &x = player.getComponent<Inventory>();
    auto i = 0;
}

GameScene::~GameScene()
{
    player.destroy();
}

void GameScene::update(float p_deltaTime)
{
    loadNearbyWorld();

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
    for (auto [entity, transform, collision] : renderView.each())
    {
        camera.drawRect(collision.box.x + transform.pos.x, collision.box.y + transform.pos.y, collision.box.width, collision.box.height);
    }

    CALI_DEBUG_TILECOL_RENDER
}

void GameScene::handlePlayerInput()
{
    player.getComponent<VelocityComponent>()._delta = Input::getInputDirection();
}

#include <iostream>

void GameScene::handleVelocity(float p_deltaTime)
{
    static auto wall = AABB{0, 0, 3, 3};

    auto renderView = registry.view<VelocityComponent, TransformComponent, CollisionComponent>();
    for (auto [entity, velocity, transform, collision] : renderView.each())
    {
        if (velocity._delta == Vec2::Zero)
            continue;
        velocity._delta.normalize();

        // from here on goes shitty implemented collision :)
        auto newPos = transform.pos + velocity._delta * p_deltaTime * velocity.speed;

        int leftTile = std::floor((newPos.x + collision.box.x) / DEFAULT_BLOCK_SIZE);
        int rightTile = std::floor((newPos.x + collision.box.x + collision.box.width) / DEFAULT_BLOCK_SIZE);
        int topTile = std::floor((newPos.y + collision.box.y) / DEFAULT_BLOCK_SIZE);
        int bottomTile = std::floor((newPos.y + collision.box.y + collision.box.height) / DEFAULT_BLOCK_SIZE);

        CALI_DEBUG_TILECOL_CLEAR
        for (int tileX = leftTile; tileX <= rightTile; tileX++)
        {
            for (int tileY = topTile; tileY <= bottomTile; tileY++)
            {
                auto tile = world.getTileAt(tileX, tileY);
                CALI_DEBUG_TILECOL_SET(tile)
                auto tileCol = tile->collision(entity);
                if (tileCol == nullptr)
                    continue;
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

    auto &transform = player.getComponent<TransformComponent>();
    int w, h;
    SDL_GetRendererOutputSize(Window::renderer, &w, &h);
    Vec2 offset = Vec2{(transform.pos.x * camera.scale) - w / 2 + (transform.size.x * camera.scale) / 2, (transform.pos.y * camera.scale) - h / 2 + (transform.size.y * camera.scale) / 2};
    camera.offset.fixLerp(offset, smoothSpeed * p_deltaTime, 0.01);
}

void GameScene::loadNearbyWorld()
{
    auto &pl = trans(player);
    int leftChunk = std::floor((pl.pos.x) / (DEFAULT_BLOCK_SIZE * CHUNK_SIZE));
    int rightChunk = std::floor((pl.pos.x + pl.size.x) / (DEFAULT_BLOCK_SIZE * CHUNK_SIZE));
    int topChunk = std::floor((pl.pos.y) / (DEFAULT_BLOCK_SIZE * CHUNK_SIZE));
    int bottomChunk = std::floor((pl.pos.y + pl.size.y) / (DEFAULT_BLOCK_SIZE * CHUNK_SIZE));

    for (ChunkMap::iterator it = world.chunks.begin(); it != world.chunks.end();)
    {
        if (it->first.first < leftChunk - 2 || it->first.first > rightChunk + 2 || it->first.second < topChunk - 2 || it->first.second > bottomChunk + 2)
        {
            std::cout << "should remove " << it->first.first << " , " << it->first.second << std::endl;
            // TODO: call destructor
            world.chunks.erase(it++);
        }
        else
        {
            it++;
        }
    }

    for (auto const &[key, chunk] : world.chunks)
    {
        if (key.first < leftChunk - 2 || key.first > rightChunk + 2 || key.second < topChunk - 2 || key.second > bottomChunk + 2)
        {
            std::cout << "should remove " << key.first << " , " << key.second << std::endl;
        }
    }

    for (int chunkX = leftChunk - 2; chunkX <= rightChunk + 2; chunkX++)
    {
        for (int chunkY = topChunk - 2; chunkY <= bottomChunk + 2; chunkY++)
        {
            world.tryLoadChunk(chunkX, chunkY, worldGen);
        }
    }
}

void GameScene::renderSprites()
{
    auto renderView = registry.view<SpriteComponent, TransformComponent>();
    for (auto [entity, sprite, transform] : renderView.each())
    {
        auto src = SDL_Rect{0, 0, 32, 32};
        camera.render(sprite.texture, src, Vec2{transform.pos.x, transform.pos.y}, Vec2{transform.size.x, transform.size.y});
    }
}