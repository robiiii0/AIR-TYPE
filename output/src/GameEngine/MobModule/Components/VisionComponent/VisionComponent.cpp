/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** VisionComponent
*/

#include "VisionComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::VisionComponent::VisionComponent(
    std::uint32_t id, std::string component_name, std::any value)
{
    if (value.type() == typeid(int)) {
        _id = id;
        _component_name = "AttackComponent";
        _vision = std::any_cast<int>(value);
    } else
        throw std::runtime_error("VisionComponent value is not int");
}

Engine::MobModule::Components::VisionComponent::~VisionComponent() {}

void Engine::MobModule::Components::VisionComponent::execute() {}

std::any& Engine::MobModule::Components::VisionComponent::get()
{
    _ptr = _vision;
    return _ptr;
}

std::string Engine::MobModule::Components::VisionComponent::getName() const
{
    return _component_name;
}
