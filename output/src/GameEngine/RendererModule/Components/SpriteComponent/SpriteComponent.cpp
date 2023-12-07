/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"
#include <stdexcept>

Engine::RendererModule::Components::SpriteComponent::SpriteComponent(
    std::uint32_t id, std::string component_name, std::any value)
{
    _id = id;
    _component_name = component_name;
    if (value.type() != typeid(std::string))
        throw std::runtime_error("SpriteComponent: value is not a string");
    else {

        _path = std::any_cast<std::string>(value);
        _ptr = value;
    }
}

Engine::RendererModule::Components::SpriteComponent::~SpriteComponent()
{
}

void Engine::RendererModule::Components::SpriteComponent::execute()
{
}

std::any& Engine::RendererModule::Components::SpriteComponent::get()
{
    return (_ptr);
}

std::string Engine::RendererModule::Components::SpriteComponent::getName() const
{
    return (_component_name);
}

