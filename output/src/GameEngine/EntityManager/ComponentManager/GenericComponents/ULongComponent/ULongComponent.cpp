/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ULongComponent
*/

#include "ULongComponent.hpp"

Engine::Entity::Component::GenericComponents::ULongComponent::ULongComponent(
    unsigned long data) {
    _value = data;
}

Engine::Entity::Component::GenericComponents::ULongComponent::
    ~ULongComponent() {}

void Engine::Entity::Component::GenericComponents::ULongComponent::execute() {
    std::cout << "Executing ULongComponent" << std::endl;
}
