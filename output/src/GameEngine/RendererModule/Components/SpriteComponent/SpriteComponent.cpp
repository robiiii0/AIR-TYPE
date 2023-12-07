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
    _component_name = "SpriteComponent";
    if (value.type() != typeid(std::string))
        throw std::runtime_error("SpriteComponent: value is not a string");
    else {

        _path = std::any_cast<std::string>(value);
        if (!_texture.loadFromFile(_path))
            throw std::runtime_error("SpriteComponent: texture not found");
        _sprite.setTexture(_texture);
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

void Engine::RendererModule::Components::SpriteComponent::setRotation(
    float rotation)
{
    _sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::SpriteComponent::setScale(float x,
    float y)
{
    _sprite.setScale(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setOrigin(float x,
    float y)
{
    _sprite.setOrigin(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setRepeated(
    bool repeated)
{
    _texture.setRepeated(repeated);
}

void Engine::RendererModule::Components::SpriteComponent::setSmooth(bool smooth)
{
    _texture.setSmooth(smooth);
}

void Engine::RendererModule::Components::SpriteComponent::setPosition(float x,
    float y)
{
    _sprite.setPosition(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setTextureRect(
    const sf::IntRect& rect)
{
    _sprite.setTextureRect(rect);
}