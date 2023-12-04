/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** DefenseComponent
*/

#include "DefenseComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::DefenseComponent::DefenseComponent(
    std::uint32_t id, std::string component_name, std::any value) {
    if (value.type() == typeid(int)) {
        _id = id;
        _component_name = "DefenseComponent";
        _defense = std::any_cast<int>(value);
    } else
        throw std::runtime_error("DefenseComponent value is not int");
}

Engine::MobModule::Components::DefenseComponent::~DefenseComponent() = default;

void Engine::MobModule::Components::DefenseComponent::execute() {}

std::any& Engine::MobModule::Components::DefenseComponent::get() {
    _ptr = _defense;
    return _ptr;
}

std::string Engine::MobModule::Components::DefenseComponent::getName() const {
    return _component_name;
}
