#pragma once

#include <string>
#include <entt/entt.hpp>

class Entity;

class Scene
{
public:
    Scene();
    ~Scene();
    
    Entity createEntity(std::string p_tag);

    friend class Entity;
private:
    entt::registry registry;
};