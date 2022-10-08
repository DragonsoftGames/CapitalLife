#include "ecs/Entity.hpp"

Entity::Entity()
    : entityHandle(entt::entity(0)), scene(nullptr)
{
}

Entity::Entity(entt::entity p_entityHandle, Scene *p_scene)
    : entityHandle(p_entityHandle), scene(p_scene)
{
}