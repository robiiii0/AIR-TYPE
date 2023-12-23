/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotCreateEntity
*/

#include "CouldNotCreateEntity.hpp"

Engine::EntityManager::CouldNotCreateEntity::CouldNotCreateEntity() {}

Engine::EntityManager::CouldNotCreateEntity::~CouldNotCreateEntity() {}

const char *Engine::EntityManager::CouldNotCreateEntity::what() const noexcept {
    return "Could not create entity";
}
