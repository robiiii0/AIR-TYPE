/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#include "ComponentManager.hpp"

#include "IComponent/IComponent.hpp"

Engine::Entity::Component::ComponentManager::ComponentManager() {}

Engine::Entity::Component::ComponentManager::~ComponentManager() {}

bool Engine::Entity::Component::ComponentManager::addComponent(
    std::uint32_t entity, IComponent *component) {


    return false;
}

// template<typename Component>
// bool Engine::EntityManager::Component<Component>::removeComponent(
//     std::uint32_t entity, Component component) {
//         entity
//     return false;
// }

// template<typename Component>
// bool Engine::EntityManager::Component<Component>::RemoveAllComponents(
//     std::uint32_t entity) {
//     return false;
// }

// template<typename Component>
// Component Engine::EntityManager::Component<Component>::getComponent(
//     std::uint32_t entity) {
//     return Component();
// }

// template<typename Component>
// bool Engine::EntityManager::Component<Component>::hasComponent(
//     std::uint32_t entity) {
//     return false;
// }
