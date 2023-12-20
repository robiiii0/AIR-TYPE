/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotRemoveComponent
*/

#include "CouldNotRemoveComponent.hpp"

Engine::EntityManager::CouldNotRemoveComponent::CouldNotRemoveComponent() {}

Engine::EntityManager::CouldNotRemoveComponent::~CouldNotRemoveComponent() {}

const char *Engine::EntityManager::CouldNotRemoveComponent::what()
    const noexcept {
    return "Could not remove component";
}
