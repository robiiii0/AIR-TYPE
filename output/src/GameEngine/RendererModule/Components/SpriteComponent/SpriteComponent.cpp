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
    _sprite.setTexture(texture);
    this->_pos = value.pos;
    this->_scale = value.scale;
    this->_color = value.color;
    this->_rotation = value.rotation;
    this->_Playable = value.Playable;


    _sprite.setScale(_scale);
    sf::FloatRect texture_bounds = _sprite.getGlobalBounds();
    _sprite.setPosition({_pos.x - texture_bounds.width /
                                           2,  // ? What does the 2 represent ?
                         _pos.y - texture_bounds.height / 2});
    _sprite.setColor(_color);
    _sprite.setRotation(_rotation);

    _pos.x = _pos.x - texture_bounds.width / 2;
    _pos.y = _pos.y - texture_bounds.height / 2;
}


void Engine::RendererModule::Components::SpriteComponent::handleEvent(int key) {
    if (_Playable) {
        if (key == sf::Keyboard::Up) {
            this->_sprite.setPosition(
                this->_sprite.getPosition().x,
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

void Engine::RendererModule::Components::SpriteComponent::setOrigin(float x,
                                                                    float y) {
    _sprite.setOrigin(x, y);
}

void Engine::RendererModule::Components::SpriteComponent::setPosition(float x,
                                                                      float y) {
    _sprite.setPosition(x + _pos.x, y + _pos.y);
}

void Engine::RendererModule::Components::SpriteComponent::setTextureRect(
    const sf::IntRect &rect) {
    _sprite.setTextureRect(rect);
}
