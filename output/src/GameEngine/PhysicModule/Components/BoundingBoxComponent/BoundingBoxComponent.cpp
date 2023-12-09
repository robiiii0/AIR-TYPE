/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** BoundingBoxComponent
*/

#include "BoundingBoxComponent.hpp"

Engine::Physic::Components::BoundingBoxComponent::BoundingBoxComponent(
    std::any value)
{
    if (value.type() == typeid(std::pair<std::pair<float, float>, std::pair<int, int>>)) {
        _component_name = "BoundingBoxComponent";
        _value = std::any_cast<std::pair<std::pair<float, float>, std::pair<int, int>>>(value);
    }
}

Engine::Physic::Components::BoundingBoxComponent::~BoundingBoxComponent()
{
}

void Engine::Physic::Components::BoundingBoxComponent::execute()
{
}

std::any &Engine::Physic::Components::BoundingBoxComponent::get()
{
    return (_value);
}

std::string Engine::Physic::Components::BoundingBoxComponent::getName() const
{
    return (_component_name);
}

void Engine::Physic::Components::BoundingBoxComponent::setBoundingBox(std::pair<std::pair<float, float>, std::pair<int, int>> pos)
{
    _pos = pos.first;
    _size = pos.second;
    _value = std::make_pair(_pos, _size);
}
