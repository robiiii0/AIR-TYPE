/*
** EPITECH PROJECT, 2023
** output
** File description:
** ShotComponent
*/

#include "ShotComponent.hpp"

Engine::RendererModule::Components::ShotComponent::ShotComponent(
    ShotData &value, sf::Texture &texture) :
    _pos(value.pos), _scale(value.scale), _sprite(texture) {
    _sprite.setPosition(_pos);
    _sprite.setScale(_scale);
    _sprite.move(4, 4);
}

Engine::RendererModule::Components::ShotComponent::~ShotComponent() {}

void Engine::RendererModule::Components::ShotComponent::execute() {}

void Engine::RendererModule::Components::ShotComponent::handleEvent(int key) {}

sf::Drawable &Engine::RendererModule::Components::ShotComponent::getDrawable() {
    return _sprite;
}
