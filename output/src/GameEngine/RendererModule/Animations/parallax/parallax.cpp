/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** parallax
*/

#include "Parallax.hpp"

#include <iostream>
#include <random>

#include "../../../../Client/src/Game/Game.hpp"

void Engine::RendererModule::Components::parallaxComponent::execute() {}

Engine::RendererModule::Components::parallaxComponent::parallaxComponent(
    parallaxData &value, sf::Texture &texture) :
    _data(value) {
    _data._sprite = value._sprite;
    _data._sprite.setTexture(texture);
    if (value.isAnimated == true) {
        _data.isAnimated = true;
        _data.rect.width = value.rect.width;
        _data.rect.height = value.rect.height;
        _data.rect.left = value.rect.left;
        _data.rect.top = value.rect.top;
        _data._sprite.setTextureRect(_data.rect);
    }
    _data._sprite.setScale(value._scale.first, value._scale.second);
    sf::FloatRect text_bounds = _data._sprite.getGlobalBounds();
    _data._sprite.setPosition({value._pos.first - text_bounds.width / 2,
                               value._pos.second - text_bounds.height / 2});

    _data._name = value._name;
    _data._movement = value._movement;
    std::cout << "sprite for paralax created" << std::endl;
}

sf::Drawable &
    Engine::RendererModule::Components::parallaxComponent::getDrawable() {
    return _data._sprite;
}

void Engine::RendererModule::Components::parallaxComponent::setRotation(
    float rotation) {
    _data._sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::parallaxComponent::setScale(float x,
                                                                     float y) {
    _data._sprite.setScale(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::setOrigin(float x,
                                                                      float y) {
    _data._sprite.setOrigin(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::setTextureRect(
    const sf::IntRect &rect) {
    _data._sprite.setTextureRect(rect);
}

void Engine::RendererModule::Components::parallaxComponent::setPosition(
    float x, float y) {
    sf::FloatRect text_bounds = _data._sprite.getGlobalBounds();

    _data._sprite.setPosition({x, y});
}

void Engine::RendererModule::Components::parallaxComponent::setMovement(
    float x, float y) {
    _data._movement = std::make_pair(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::Animation() {
    if (_data.rect.left >= 15000) {
        _data.rect.left = 0;
    } else {
        _data.rect.left += _data.rect.width;
    }
    _data._sprite.setTextureRect(_data.rect);
}

void Engine::RendererModule::Components::parallaxComponent::runParallax() {
    sf::FloatRect text_bounds = _data._sprite.getGlobalBounds();

    if (_data._sprite.getPosition().x < -text_bounds.width) {
        if (_data.isAnimated == true) {
            std::random_device rd;

            std::default_random_engine generator(rd());

            std::uniform_int_distribution<int> distribution(5, 8);

            int random_number = distribution(generator);
            std::cout << _data._pos.first << std::endl;
            setPosition((text_bounds.width + _data.rect.width + (50 * random_number)),
                        (0));

            _data._movement.second = random_number;
        } else {
            setPosition((text_bounds.width + _data.rect.width), 0);
        }
    }
    if (_data.isAnimated == true) {
        Animation();
    }

    if ((_data._sprite.getPosition().y > text_bounds.height) || (_data._sprite.getPosition().y < 0 )) {
        _data._movement.second = _data._movement.second * -1;
    }

    _data._sprite.move({_data._movement.first, _data._movement.second});
}

Engine::RendererModule::Components::parallaxComponent::~parallaxComponent() {}
