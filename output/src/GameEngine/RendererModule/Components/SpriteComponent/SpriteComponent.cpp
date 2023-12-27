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
    _sprite.setTexture(texture);
    _sprite.setScale(_data.scale);
    sf::FloatRect texture_bounds = _sprite.getGlobalBounds();
    _sprite.setPosition({_data.pos.x - texture_bounds.width /
                                           2,  // ? What does the 2 represent ?
                         _data.pos.y - texture_bounds.height / 2});
    _sprite.setColor(_data.color);
    _sprite.setRotation(_data.rotation);
    _relative_pos.x = _data.pos.x - texture_bounds.width / 2;
    _relative_pos.y = _data.pos.y - texture_bounds.height / 2;
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
    _data._sprite.setPosition(x + _relative_pos.x, y + _relative_pos.y);
}

void Engine::RendererModule::Components::SpriteComponent::setTextureRect(
    const sf::IntRect &rect) {
    _data._sprite.setTextureRect(rect);
}
