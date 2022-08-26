#pragma once

#include <entt/entt.hpp>
#include "Window.hpp"

class Entity;

class Scene
{
friend class Entity;
public:
    virtual ~Scene() {};

    virtual void update(float deltaTime) = 0;
    virtual void render(Window* p_window) = 0;

protected:
    Entity createEntity();
    entt::registry registry;
    

private:
};