/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** DefenseComponent
*/

#include "DefenseComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::DefenseComponent::DefenseComponent(std::any value) {
    if (value.type() == typeid(int)) {
        _component_name = "DefenseComponent";
        _defense = std::any_cast<int>(value);
        _ptr = value;
    } else
        throw std::runtime_error("DefenseComponent value is not int");
}

Engine::MobModule::Components::DefenseComponent::~DefenseComponent() = default;

void Engine::MobModule::Components::DefenseComponent::execute() {}

std::any& Engine::MobModule::Components::DefenseComponent::get() {
    return _ptr;
}

std::string Engine::MobModule::Components::DefenseComponent::getName() const {
    return _component_name;
}
