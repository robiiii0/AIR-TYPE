/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

template<typename Component>
Engine::EntityManager::ComponentManager<Component>::ComponentManager() {}

template<typename Component>
Engine::EntityManager::ComponentManager<Component>::~ComponentManager() {}

template<typename Component>
bool Engine::EntityManager::ComponentManager<Component>::addComponent(
    std::uint32_t entity, Component component) {
    return flase;
}

template<typename Component>
bool Engine::EntityManager::ComponentManager<Component>::removeComponent(
    std::uint32_t entity, Component component) {
        entity
    return false;
}

template<typename Component>
bool Engine::EntityManager::ComponentManager<Component>::RemoveAllComponents(
    std::uint32_t entity) {
    return false;
}

template<typename Component>
Component Engine::EntityManager::ComponentManager<Component>::getComponent(
    std::uint32_t entity) {
    return Component();
}

template<typename Component>
bool Engine::EntityManager::ComponentManager<Component>::hasComponent(
    std::uint32_t entity) {
    return false;
}
