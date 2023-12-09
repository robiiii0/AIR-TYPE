/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** PositionComponet
*/

#include "PositionComponent.hpp"

Engine::Physic::Components::PositionComponent::PositionComponent(std::any value)
{
    _value = value;
    _component_name = "PositionComponent";
    _pos = std::any_cast<std::pair<float, float>>(value);
}

Engine::Physic::Components::PositionComponent::~PositionComponent()
{
}

void Engine::Physic::Components::PositionComponent::execute()
{
}

std::any &Engine::Physic::Components::PositionComponent::get()
{
    return (_value);
}

std::string Engine::Physic::Components::PositionComponent::getName() const
{
    return (_component_name);
}

void Engine::Physic::Components::PositionComponent::setPos(std::pair<float, float> pos)
{
    _pos = pos;
}
