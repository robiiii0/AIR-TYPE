/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

#include <iostream>
#include "IComponent/IComponent.hpp"

Engine::Entity::Component::ComponentManager::ComponentManager()
{
    _component_ids.fill(0);
}

Engine::Entity::Component::ComponentManager::~ComponentManager() {}

std::uint32_t Engine::Entity::Component::ComponentManager::addComponent(
    Entity& entity, IComponent& component)
{
    std::cout << "Added component " << component.getName() << " to entity "
              << entity.id << std::endl;
    entity.components.push_back(&component);
    return 0;
}

bool Engine::Entity::Component::ComponentManager::removeComponent(
    Entity& entity, std::string component_name)
{
    for (std::uint32_t i = 0; i < entity.components.size(); i++) {
        if (entity.components[i]->getName() == component_name) {
            entity.components.erase(entity.components.begin() + i);
            return true;
        }
    }
    return false;
}

bool Engine::Entity::Component::ComponentManager::removeAllComponents(
    Entity& entity)
{
    _component_ids[entity.id] = 0;
    entity.components.clear();
    return false;
}

Engine::Entity::Component::IComponent& Engine::Entity::Component::
    ComponentManager::getComponent(
        Entity& entity, std::uint32_t component_id)
{
    throw std::runtime_error("Component not found");
}

bool Engine::Entity::Component::ComponentManager::hasComponent(
    Entity& entity, std::string component_name)
{
    for (std::uint32_t i = 0; i < entity.components.size(); i++) {
        if (entity.components[i]->getName() == component_name) {
            return true;
        }
    }
    return false;
}
