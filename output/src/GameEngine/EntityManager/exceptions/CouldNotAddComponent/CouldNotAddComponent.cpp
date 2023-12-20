/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotAddComponent
*/

#include "CouldNotAddComponent.hpp"

Engine::EntityManager::CouldNotAddComponent::CouldNotAddComponent() {}

Engine::EntityManager::CouldNotAddComponent::~CouldNotAddComponent() {}

const char *Engine::EntityManager::CouldNotAddComponent::what() const noexcept {
    return "Could not add component";
}
