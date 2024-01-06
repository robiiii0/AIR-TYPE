/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#include "EnemyComponent.hpp"

#include <iostream>
#include <stdexcept>

Engine::RendererModule::Components::EnemyComponent::EnemyComponent(
    EnemyData &value, sf::Texture &texture) {
    sf::Sprite Sprite;
    this->_sprite = Sprite;
    this->_sprite.setTexture(texture);
    this->_pos = value.pos;
    this->_scale = value.scale;
    this->_color = value.color;
    this->_rotation = value.rotation;
    this->_Playable = value.Playable;

    this->_sprite.setScale({this->_scale.x * -1, this->_scale.y});
    sf::FloatRect texture_bounds = _sprite.getGlobalBounds();
    _sprite.setPosition({this->_pos.x, this->_pos.y});
    _sprite.setColor(_color);
    _sprite.setRotation(_rotation);
    std::cout << "EnemyComponent created" << std::endl;
    std::cout << this->_scale.x << this->_scale.y << std::endl;
    std::cout << this->_pos.x << this->_pos.y << std::endl;
}

void Engine::RendererModule::Components::EnemyComponent::handleEvent(int key) {
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
    Engine::RendererModule::Components::EnemyComponent::getDrawable() {
    return _sprite;
}

Engine::RendererModule::Components::EnemyComponent::~EnemyComponent() {}

void Engine::RendererModule::Components::EnemyComponent::execute() {}

void Engine::RendererModule::Components::EnemyComponent::setRotation(
    float rotation) {
    _sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::EnemyComponent::setScale(float x,
                                                                   float y) {
    _sprite.setScale(x, y);
}

void Engine::RendererModule::Components::EnemyComponent::setPosition(float x,
                                                                      float y) {
    _sprite.setPosition(x + _pos.x, y + _pos.y);
}

void Engine::RendererModule::Components::EnemyComponent::setTextureRect(
    const sf::IntRect &rect) {
    _sprite.setTextureRect(rect);
}
