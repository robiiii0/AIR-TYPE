/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotFindComponent
*/

#include "CouldNotFindComponent.hpp"

Engine::EntityManager::CouldNotFindComponent::CouldNotFindComponent() {}

Engine::EntityManager::CouldNotFindComponent::~CouldNotFindComponent() {}

const char *Engine::EntityManager::CouldNotFindComponent::what()
    const noexcept {
    return "Could not find component";
}
