#pragma once

#include <entt/entt.hpp>
#include "Window.hpp"

class Entity;

class Scene
{
friend class Entity;
public:
    virtual ~Scene() {};

    virtual void update() = 0;
    virtual void render(Window* p_window) = 0;

protected:
    Entity createEntity();

private:
    entt::registry registry;
};