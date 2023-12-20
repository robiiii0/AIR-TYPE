/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** NoComponent
*/

#include "NoComponent.hpp"

Engine::EntityManager::NoComponent::NoComponent() {}

Engine::EntityManager::NoComponent::~NoComponent() {}

const char *Engine::EntityManager::NoComponent::what() const noexcept {
    return "No component";
}
