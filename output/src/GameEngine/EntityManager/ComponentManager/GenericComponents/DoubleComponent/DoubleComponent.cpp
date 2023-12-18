/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** DoubleComponent
*/

#include "DoubleComponent.hpp"

#include <stdexcept>

Engine::Entity::Component::GenericComponents::DoubleComponent::DoubleComponent(
    double data) {
    _value = data;
}

Engine::Entity::Component::GenericComponents::DoubleComponent::
    ~DoubleComponent() {}

void Engine::Entity::Component::GenericComponents::DoubleComponent::execute() {}
