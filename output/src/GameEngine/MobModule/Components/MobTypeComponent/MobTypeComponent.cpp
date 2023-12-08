/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MobTypeComponent
*/

#include "MobTypeComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::MobTypeComponent::MobTypeComponent(std::any value) {
    if (value.type() == typeid(int)) {
        _component_name = "MobTypeComponent";
        _type = std::any_cast<int>(value);
    _ptr = _type;

    } else
        throw std::runtime_error("MobTypeComponent value is not int");
}

Engine::MobModule::Components::MobTypeComponent::~MobTypeComponent() = default;

void Engine::MobModule::Components::MobTypeComponent::execute() {}

std::any& Engine::MobModule::Components::MobTypeComponent::get() {
    return _ptr;
}

std::string Engine::MobModule::Components::MobTypeComponent::getName() const {
    return _component_name;
}
