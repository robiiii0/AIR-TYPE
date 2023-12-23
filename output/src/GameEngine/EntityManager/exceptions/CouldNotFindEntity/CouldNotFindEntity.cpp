/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotFindEntity
*/

#include "CouldNotFindEntity.hpp"

Engine::EntityManager::CouldNotFindEntity::CouldNotFindEntity() {}

Engine::EntityManager::CouldNotFindEntity::~CouldNotFindEntity() {}

const char *Engine::EntityManager::CouldNotFindEntity::what() const noexcept {
    return "Could not find entity";
}
