#pragma once

#include "Scene.hpp"

class Entity
{
public:
    Entity();
    Entity(entt::entity p_entityHandle, Scene* p_scene);

    template<typename T, typename... Args>
    T& addComponent(Args&&... args)
    {
        return scene->registry.emplace<T>(entityHandle, std::forward<Args>(args)...);
    }

    template<typename T>
    T& getComponent()
    {
        return scene->registry.get<T>(entityHandle);
    }

    template<typename T>
    void removeComponent()
    {
        return scene->registry.remove<T>(entityHandle);
    }

    template<typename T>
    bool hasComponent()
    {
        return scene->registry.all_of<T>(entityHandle);
    }
private:
    entt::entity entityHandle;
    Scene* scene;
};