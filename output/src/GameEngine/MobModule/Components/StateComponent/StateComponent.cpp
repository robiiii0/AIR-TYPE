/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** StateComponent
*/

#include "StateComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::StateComponent::StateComponent(std::any value) {
    if (value.type() == typeid(bool)) {
        _component_name = "StateComponent";
        _state = std::any_cast<bool>(value);
        _ptr = _state;
    } else
        throw std::runtime_error("StateComponent value is not bool");
}

Engine::MobModule::Components::StateComponent::~StateComponent() {}

void Engine::MobModule::Components::StateComponent::execute() {}

std::any& Engine::MobModule::Components::StateComponent::get() {
    return _ptr;
}

std::string Engine::MobModule::Components::StateComponent::getName() const {
    return _component_name;
}
