/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** VisionComponent
*/

#include "VisionComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::VisionComponent::VisionComponent(
    std::any value) {
    if (value.type() == typeid(int)) {
        _component_name = "VisionComponent";
        _vision = std::any_cast<int>(value);
        _ptr = _vision;
    } else
        throw std::runtime_error("VisionComponent value is not int");
}

Engine::MobModule::Components::VisionComponent::~VisionComponent() {}

void Engine::MobModule::Components::VisionComponent::execute() {}

std::any& Engine::MobModule::Components::VisionComponent::get() { return _ptr; }

std::string Engine::MobModule::Components::VisionComponent::getName() const {
    return _component_name;
}
