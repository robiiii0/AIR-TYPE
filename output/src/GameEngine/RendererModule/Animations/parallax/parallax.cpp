/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** parallax
*/

#include "Parallax.hpp"

#include <iostream>

#include "../../../../Client/src/Game/Game.hpp"

void Engine::RendererModule::Components::parallaxComponent::execute() {}

Engine::RendererModule::Components::parallaxComponent::parallaxComponent(
    parallaxData &value, sf::Texture &texture) :
    _data(value) {
    _data._sprite = value._sprite;
    _data._sprite.setTexture(texture);
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
    _data._sprite.setPosition(x, y);
}

void Engine::RendererModule::Components::parallaxComponent::setMovement(
    float x, float y) {
    _data._movement = std::make_pair(x, y);
}


void Engine::RendererModule::Components::parallaxComponent::runParallax()
{
    _data._sprite.move({_data._movement.first,_data._movement.second });
}

Engine::RendererModule::Components::parallaxComponent::~parallaxComponent() {}
