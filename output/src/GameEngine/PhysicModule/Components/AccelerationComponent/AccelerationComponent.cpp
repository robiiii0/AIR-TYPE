/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#include "AccelerationComponent.hpp"

Engine::Physic::Components::AccelerationComponent::AccelerationComponent(
    std::any value) {
    if (value.type() == typeid(std::pair<float, float>)) {
        _component_name = "AccelerationComponent";
        _value = std::any_cast<std::pair<float, float>>(value);
    }
}

Engine::Physic::Components::AccelerationComponent::~AccelerationComponent() {}

void Engine::Physic::Components::AccelerationComponent::execute() {}

std::any &Engine::Physic::Components::AccelerationComponent::get() {
    return (_value);
}

std::string Engine::Physic::Components::AccelerationComponent::getName() const {
    return (_component_name);
}

void Engine::Physic::Components::AccelerationComponent::setAcceleration(
    std::pair<float, float> acceleration) {
    _acceleration = acceleration;
    _value = _acceleration;
}
