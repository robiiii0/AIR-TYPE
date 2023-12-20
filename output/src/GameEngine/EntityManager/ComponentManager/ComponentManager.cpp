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

std::uint32_t Engine::Entity::Component::ComponentManager::addComponent(
    std::shared_ptr<Entity> entity, std::shared_ptr<IComponent> component) {
    entity->_components.push_back(component);
    return 0;
}

template<typename T>
bool Engine::Entity::Component::ComponentManager::removeComponent(
    std::shared_ptr<Entity> entity, T component) {
    for (std::uint32_t i = 0; i < entity->_components.size(); i++) {
        if (typeid(entity->_components[i]) == typeid(T)) {
            entity->_components.erase(entity->_components.begin() + i);
            return true;
        }
    }
    return false;
}

bool Engine::Entity::Component::ComponentManager::removeAllComponents(
    std::shared_ptr<Entity> entity) {
    _component_ids[entity->_id] = 0;
    entity->_components.clear();
    return false;
}

std::shared_ptr<Engine::Entity::Component::IComponent>
    Engine::Entity::Component::ComponentManager::getComponent(
        std::shared_ptr<Entity> entity, std::uint32_t component_id) {
    throw std::runtime_error("Component not found");
}

template<typename T>
bool Engine::Entity::Component::ComponentManager::hasComponent(
    std::shared_ptr<Entity> entity, T component) {
    for (std::uint32_t i = 0; i < entity->_components.size(); i++) {
        if (typeid(entity->_components[i]) == typeid(T)) {
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Engine::Entity::Component::IComponent>>
    Engine::Entity::Component::ComponentManager::getAllComponents(
        std::shared_ptr<Entity> entity) {
    std::vector<std::shared_ptr<Engine::Entity::Component::IComponent>>
        components;
    for (auto component : entity->_components) {
        components.push_back(component);
    }
    return components;
}
