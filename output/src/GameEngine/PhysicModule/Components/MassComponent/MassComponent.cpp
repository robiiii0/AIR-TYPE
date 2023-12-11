/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MassComponent
*/

#include "MassComponent.hpp"

Engine::Physic::Components::MassComponent::MassComponent(std::any value) {
    if (value.type() == typeid(float)) {
        _component_name = "MassComponent";
        _value = std::any_cast<float>(value);
    }
}

Engine::Physic::Components::MassComponent::~MassComponent() {}

void Engine::Physic::Components::MassComponent::execute() {}

std::any &Engine::Physic::Components::MassComponent::get() { return (_value); }

std::string Engine::Physic::Components::MassComponent::getName() const {
    return (_component_name);
}

void Engine::Physic::Components::MassComponent::setMass(float mass) {
    _mass = mass;
    _value = _mass;
}
