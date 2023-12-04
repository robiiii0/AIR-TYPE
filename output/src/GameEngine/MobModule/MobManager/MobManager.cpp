/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MobManager
*/

#include "MobManager.hpp"

Engine::MobModule::MobManager::MobManager() {}

Engine::MobModule::MobManager::~MobManager() {}

std::uint32_t Engine::MobModule::MobManager::addComponent(
    Engine::Entity::Entity &entity,
    Engine::Entity::Component::IComponent &component) {
    entity.components.push_back(&component);
    return 0;
}

bool Engine::MobModule::MobManager::removeComponent(
    Engine::Entity::Entity &entity, std::string component_name) {
    return false;
}

bool Engine::MobModule::MobManager::removeAllComponents(
    Engine::Entity::Entity &entity) {
    return false;
}

Engine::Entity::Component::IComponent &Engine::MobModule::MobManager::
    getComponent(Engine::Entity::Entity &entity, std::string component_name) {
    return *entity.components[0];
}

bool Engine::MobModule::MobManager::hasComponent(
    Engine::Entity::Entity &entity, std::string component_name) {
    return false;
}
