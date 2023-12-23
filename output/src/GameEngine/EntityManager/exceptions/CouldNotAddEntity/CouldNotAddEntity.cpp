/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotAddEntity
*/

#include "CouldNotAddEntity.hpp"

Engine::EntityManager::CouldNotAddEntity::CouldNotAddEntity() {}

Engine::EntityManager::CouldNotAddEntity::~CouldNotAddEntity() {}

const char *Engine::EntityManager::CouldNotAddEntity::what() const noexcept {
    return "Could not add entity";
}
