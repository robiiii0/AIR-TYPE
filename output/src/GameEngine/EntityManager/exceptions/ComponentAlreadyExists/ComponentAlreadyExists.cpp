/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ComponentAlreadyExists
*/

#include "ComponentAlreadyExists.hpp"

Engine::EntityManager::ComponentAlreadyExists::ComponentAlreadyExists()
{
}

Engine::EntityManager::ComponentAlreadyExists::~ComponentAlreadyExists()
{
}

const char *Engine::EntityManager::ComponentAlreadyExists::what() const noexcept
{
    return "Component already exists";
}
