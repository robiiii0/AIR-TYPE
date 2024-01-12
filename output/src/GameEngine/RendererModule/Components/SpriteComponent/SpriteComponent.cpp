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
    SpriteData &value, sf::Texture &texture) {
    sf::Sprite Sprite;
    this->_sprite = Sprite;
    this->_sprite.setTexture(texture);
    this->_pos = value.pos;
    this->_scale = value.scale;
    this->_color = value.color;
    this->_rotation = value.rotation;
    this->_Playable = value.Playable;
    this->_id = value.id;

    this->_sprite.setScale({this->_scale.x, this->_scale.y});
    sf::FloatRect texture_bounds = _sprite.getGlobalBounds();
    _sprite.setPosition({this->_pos.x, this->_pos.y});
    _sprite.setColor(_color);
    _sprite.setRotation(_rotation);
}

void Engine::RendererModule::Components::SpriteComponent::handleEvent(int key) {
    if (_Playable) {
        if (key == sf::Keyboard::Up) {
            this->_sprite.setPosition(this->_sprite.getPosition().x,
                                      this->_sprite.getPosition().y - 10);
        }
        if (key == sf::Keyboard::Down) {
            this->_sprite.move(0, 10);
        }
        if (key == sf::Keyboard::Left) {
            this->_sprite.move(-10, 0);
        }
        if (key == sf::Keyboard::Right) {
            this->_sprite.move(10, 0);
        }
    }
}

sf::Drawable &
    Engine::RendererModule::Components::SpriteComponent::getDrawable() {
    return _sprite;
}

Engine::RendererModule::Components::SpriteComponent::~SpriteComponent() {}

void Engine::RendererModule::Components::SpriteComponent::execute() {}

void Engine::RendererModule::Components::SpriteComponent::setRotation(
    float rotation) {
    _sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::SpriteComponent::setScale(float x,
                                                                   float y) {
    _sprite.setScale(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setPosition(float x,
                                                                      float y) {
    _sprite.setPosition(x, y);
}

uint32_t Engine::RendererModule::Components::SpriteComponent::getId() {
    return _id;
}

void Engine::RendererModule::Components::SpriteComponent::setTextureRect(
    const sf::IntRect &rect) {
    _sprite.setTextureRect(rect);
}
