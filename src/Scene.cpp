#include "Scene.hpp"

#include "ecs/Entity.hpp"

Entity Scene::createEntity()
{
    Entity entity(registry.create(), this);
    return entity;
}