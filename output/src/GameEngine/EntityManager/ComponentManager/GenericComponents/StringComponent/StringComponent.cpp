/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** StringComponent
*/

#include "StringComponent.hpp"

Engine::Entity::Component::GenericComponents::StringComponent::StringComponent(
    std::string data) {
    _value = data;
}

Engine::Entity::Component::GenericComponents::StringComponent::
    ~StringComponent() {}

void Engine::Entity::Component::GenericComponents::StringComponent::execute() {}
