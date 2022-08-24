#include "Scene.hpp"

#include "ecs/Entity.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{

}

Entity Scene::createEntity(std::string p_tag)
{
    Entity entity(registry.create(), this);
    return entity;
}