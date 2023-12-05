/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** StringComponent
*/

#include "StringComponent.hpp"

Engine::Entity::Component::GenericComponents::StringComponent::
    ~StringComponent() {}

void Engine::Entity::Component::GenericComponents::StringComponent::execute() {}

std::any& Engine::Entity::Component::GenericComponents::StringComponent::get() {
    return _value;
}

std::string
    Engine::Entity::Component::GenericComponents::StringComponent::getName()
        const {
    return _component_name;
}
