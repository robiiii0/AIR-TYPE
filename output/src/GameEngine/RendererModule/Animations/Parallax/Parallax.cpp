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
    parallaxData &value, sf::Texture &texture) {
    sf::Sprite Sprite;
    _sprite = Sprite;

    _sprite.setTexture(texture);
    std::cout << "texture loaded" << std::endl;
    if (!value.isAnimated) {
        isAnimated = false;
        rect.width = texture.getSize().x;
        rect.height = texture.getSize().y;
        rect.left = 0;
        rect.top = 0;
    } else {
        isAnimated = true;
        rect.width = value.rect.width;
        rect.height = value.rect.height;
        rect.left = value.rect.left;
        rect.top = value.rect.top;
    }
    _sprite.setTextureRect(rect);
    _sprite.setScale(value._scale.first, value._scale.second);
    sf::FloatRect text_bounds = _sprite.getGlobalBounds();
    _sprite.setPosition({value._pos.first - text_bounds.width / 2,
                               value._pos.second - text_bounds.height / 2});
    _movement = value._movement;
    _clock = value._clock;
}

sf::Drawable &
    Engine::RendererModule::Components::parallaxComponent::getDrawable() {
    return _sprite;
}

void Engine::RendererModule::Components::parallaxComponent::setRotation(
    float rotation) {
    _sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::parallaxComponent::setScale(float x,
                                                                     float y) {
    _sprite.setScale(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::setOrigin(float x,
                                                                      float y) {
    _sprite.setOrigin(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::setTextureRect(
    const sf::IntRect &rect) {
    _sprite.setTextureRect(rect);
}

void Engine::RendererModule::Components::parallaxComponent::setPosition(
    float x, float y) {
    sf::FloatRect text_bounds = _sprite.getGlobalBounds();

    _sprite.setPosition({x, y});
}

void Engine::RendererModule::Components::parallaxComponent::setMovement(
    float x, float y) {
    _movement = std::make_pair(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::Animation() {
    if (rect.left >= 15000) {
        rect.left = 0;
    } else {
        rect.left += rect.width;
    }
    _sprite.setTextureRect(rect);
}

void Engine::RendererModule::Components::parallaxComponent::runParallax() {
    sf::FloatRect text_bounds = _sprite.getGlobalBounds();

    if (_sprite.getPosition().x < -text_bounds.width) {
        if (isAnimated == true) {
            std::random_device rd;

            std::default_random_engine generator(rd());

            std::uniform_int_distribution<int> distribution(5, 8);

            int random_number = distribution(generator);
            setPosition(
                (text_bounds.width + rect.width + (50 * random_number)),
                (0));

            _movement.second = random_number;
        } else {
            setPosition((text_bounds.width + rect.width), 0);
        }
    }
    if (isAnimated == true) {
        sf::Time elapsed1 = _clock.getElapsedTime();
        if (elapsed1.asSeconds() > 0.05) {
            Animation();
            _clock.restart();
        }
    }

    if ((_sprite.getPosition().y > text_bounds.height) ||
        (_sprite.getPosition().y < 0)) {
        _movement.second = _movement.second * -1;
    }

    _sprite.move({_movement.first, _movement.second});
}

Engine::RendererModule::Components::parallaxComponent::~parallaxComponent() {}
