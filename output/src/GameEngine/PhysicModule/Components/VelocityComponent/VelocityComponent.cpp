/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** VelocityComponent
*/

#include "VelocityComponent.hpp"

Engine::Physic::Components::VelocityComponent::VelocityComponent(
    std::any value)
{
    if (value.type() == typeid(std::pair<float, float>)) {
        _component_name = "VelocityComponent";
        _value = std::any_cast<std::pair<float, float>>(value);
    }
}

Engine::Physic::Components::VelocityComponent::~VelocityComponent()
{
}

void Engine::Physic::Components::VelocityComponent::execute()
{
}

std::any &Engine::Physic::Components::VelocityComponent::get()
{
    return (_value);
}

std::string Engine::Physic::Components::VelocityComponent::getName() const
{
    return (_component_name);
}

void Engine::Physic::Components::VelocityComponent::setVelocity(std::pair<float, float> velocity)
{
    _velocity = velocity;
    _value = _velocity;
}
