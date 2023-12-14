/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

#include <iostream>

#include "IComponent/IComponent.hpp"

Engine::Entity::Component::ComponentManager::ComponentManager() {
    _component_ids.fill(0);
}

Engine::Entity::Component::ComponentManager::~ComponentManager() {}

template <typename T>
std::uint32_t Engine::Entity::Component::ComponentManager::addComponent(
    Entity<T>& entity, IComponent<T>& component) {
    std::cout << "Added component " << component.getName() << " to entity "
              << entity.id << std::endl;
    entity.components.push_back(&component);
    return 0;
}

template <typename T>
bool Engine::Entity::Component::ComponentManager::removeComponent(
    Entity<T>& entity, std::string component_name) {
    for (std::uint32_t i = 0; i < entity.components.size(); i++) {
        if (entity.components[i]->getName() == component_name) {
            entity.components.erase(entity.components.begin() + i);
            return true;
        }
    }
    return false;
}

template <typename T>
bool Engine::Entity::Component::ComponentManager::removeAllComponents(
    Entity<T>& entity) {
    _component_ids[entity.id] = 0;
    entity.components.clear();
    return false;
}

template <typename T>
Engine::Entity::Component::IComponent<T>&
    Engine::Entity::Component::ComponentManager::getComponent(
        Entity<T>& entity, std::uint32_t component_id) {
    throw std::runtime_error("Component not found");
}

template <typename T>
bool Engine::Entity::Component::ComponentManager::hasComponent(
    Entity<T>& entity, std::string component_name) {
    for (std::uint32_t i = 0; i < entity.components.size(); i++) {
        if (entity.components[i]->getName() == component_name) {
            return true;
        }
    }
    return false;
}

template <typename T>
void Engine::Entity::Component::ComponentManager::getAllComponents(
    Entity<T>& entity) {
    for (std::uint32_t i = 0; i < entity.components.size(); i++) {
        std::cout << entity.components[i]->getName() << std::endl;
    }
}
