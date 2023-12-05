/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** IAComponent
*/

#include "IAComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::IAComponent::IAComponent(
    std::uint32_t id, std::string component_name, std::any value)
{
    if (value.type() == typeid(int)) {
        _id = id;
        _component_name = "IAComponent";
        _ia = std::any_cast<int>(value);
    } else
        throw std::runtime_error("IAComponent value is not int");
}

Engine::MobModule::Components::IAComponent::~IAComponent() {}

void Engine::MobModule::Components::IAComponent::execute() {}

std::any& Engine::MobModule::Components::IAComponent::get()
{
    _ptr = _ia;
    return _ptr;
}

std::string Engine::MobModule::Components::IAComponent::getName() const
{
    return _component_name;
}
