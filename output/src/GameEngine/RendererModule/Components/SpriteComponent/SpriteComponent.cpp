/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

#include <iostream>
#include <stdexcept>

Engine::RendererModule::Components::SpriteComponent::SpriteComponent(
    SpriteData &value, sf::Texture &texture) :
    _data(value) {
    _data._sprite.setTexture(texture);
    _data.rotation = value.rotation;
    _data.scale = value.scale;
    _data.pos = value.pos;
    _data._sprite.setPosition(_data.pos);
    _data.color = value.color;
    std::cout << "sprite created" << std::endl;
}

sf::Drawable &
    Engine::RendererModule::Components::SpriteComponent::getDrawable() {
    return _sprite;
}

Engine::RendererModule::Components::SpriteComponent::~SpriteComponent() {}

void Engine::RendererModule::Components::SpriteComponent::execute() {}

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

void Engine::RendererModule::Components::SpriteComponent::setPosition(float x,
                                                                      float y) {
    _data._sprite.setPosition(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setTextureRect(
    const sf::IntRect &rect) {
    _data._sprite.setTextureRect(rect);
}
