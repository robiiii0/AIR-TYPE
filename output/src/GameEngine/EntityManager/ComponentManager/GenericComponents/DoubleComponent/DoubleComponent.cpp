/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** DoubleComponent
*/

#include "DoubleComponent.hpp"

Engine::Entity::Component::GenericComponents::DoubleComponent::
    ~DoubleComponent() {}

void Engine::Entity::Component::GenericComponents::DoubleComponent::execute() {}

std::string
    Engine::Entity::Component::GenericComponents::DoubleComponent::getName()
        const {
    return _component_name;
}

std::any& Engine::Entity::Component::GenericComponents::DoubleComponent::get() {
    return _value;
}
