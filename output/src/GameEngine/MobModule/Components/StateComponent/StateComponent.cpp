/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** StateComponent
*/

#include "StateComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::StateComponent::StateComponent(
    std::uint32_t id, std::string component_name, std::any value)
{
    if (value.type() == typeid(bool)) {
        _id = id;
        _component_name = "AttackComponent";
        _state = std::any_cast<bool>(value);
    } else
        throw std::runtime_error("StateComponent value is not bool");
}

Engine::MobModule::Components::StateComponent::~StateComponent() {}

void Engine::MobModule::Components::StateComponent::execute() {}

std::any& Engine::MobModule::Components::StateComponent::get()
{
    _ptr = _state;
    return _ptr;
}

std::string Engine::MobModule::Components::StateComponent::getName() const
{
    return _component_name;
}
