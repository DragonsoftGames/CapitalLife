#include "Scene.hpp"

#include "ecs/Entity.hpp"

Entity Scene::createEntity(std::string p_tag)
{
    Entity entity(registry.create(), this);
    p_tag.clear();
    return entity;
}