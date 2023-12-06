/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AComponent
*/

#include "AComponent.hpp"

std::uint32_t Engine::Entity::Component::AComponent::getId() const {
    return this->_id;
}

void Engine::Entity::Component::AComponent::setId(std::uint32_t id) {
    this->_id = id;
}
