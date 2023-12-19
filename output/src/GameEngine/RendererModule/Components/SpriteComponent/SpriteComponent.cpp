/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

#include <stdexcept>
#include <iostream>

Engine::RendererModule::Components::SpriteComponent::SpriteComponent(
    SpriteData &value) : _data(value) {
    if (!_data._texture.loadFromFile(value._path))
        throw std::runtime_error("SpriteComponent: texture not found");
    _data._sprite.setTexture(_data._texture);
    std::cout << "sprite created" << std::endl;
}

sf::Drawable &Engine::RendererModule::Components::SpriteComponent::getDrawable()
{
    return _data._sprite;
}


Engine::RendererModule::Components::SpriteComponent::~SpriteComponent() {}

void Engine::RendererModule::Components::SpriteComponent::execute() {}

std::string& Engine::RendererModule::Components::SpriteComponent::get() {
    return (_data._ptr);
}

void Engine::RendererModule::Components::SpriteComponent::setRotation(
    float rotation) {
   _data._sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::SpriteComponent::setScale(float x,
                                                                   float y) {
   _data._sprite.setScale(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setOrigin(float x,
                                                                    float y) {
    _data._sprite.setOrigin(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setRepeated(
    bool repeated) {
    _data._texture.setRepeated(repeated);
}

void Engine::RendererModule::Components::SpriteComponent::setSmooth(
    bool smooth) {
    _data._texture.setSmooth(smooth);
}

void Engine::RendererModule::Components::SpriteComponent::setPosition(float x,
                                                                      float y) {
    _data._sprite.setPosition(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setTextureRect(
    const sf::IntRect& rect) {
    _data._sprite.setTextureRect(rect);
}
