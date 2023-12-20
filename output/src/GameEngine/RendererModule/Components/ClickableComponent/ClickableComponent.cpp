/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ClickableComponent
*/

#include "ClickableComponent.hpp"

#include <iostream>
#include <stdexcept>

Engine::RendererModule::Components::ClickableComponent::ClickableComponent(
    ClickableData &value) :
    _data(value) {
    if (!_data._texture.loadFromFile(value._path))
        throw std::runtime_error("SpriteComponent: texture not found");
    _data._sprite.setTexture(_data._texture);
    _data._sprite.setPosition(_data._pos.first, _data._pos.second);
    _data._sprite.setScale(_data._scale.first, _data._scale.second);
    std::cout << "sprite button created" << std::endl;
}

std::pair<float, float> Engine::RendererModule::Components::ClickableComponent::getPos() const {
    return _data._pos;
}

sf::Drawable &
    Engine::RendererModule::Components::ClickableComponent::getDrawable() {
    return _data._sprite;
}

Engine::RendererModule::Components::ClickableComponent::~ClickableComponent() {}

void Engine::RendererModule::Components::ClickableComponent::execute() {}

void Engine::RendererModule::Components::ClickableComponent::update() {
    // TODO: MousePosition and Entity position in parameters ?
    // Get MousePosition
    // Get Entity Position

    // Check if MousePosition is in Entity Position
    // Update _data.isHovered

    // Check if Mouse is clicked
    // Update _data.isClicked
}

bool Engine::RendererModule::Components::ClickableComponent::isHovered() const {
    return _data.isHovered;
}

bool Engine::RendererModule::Components::ClickableComponent::isClicked(
    std::pair<float, float> mousePos) const {

        std::cout << "-------------------------------------" << std::endl;
        std::cout << "mousePos: " << mousePos.first << ", " << mousePos.second << std::endl;
        std::cout << "pos: " << _data._pos.first << ", " << _data._pos.second << std::endl;
        std:: cout << "getSpriteSize" << _data._texture.getSize().x * _data._scale.first << ", " << _data._texture.getSize().y * _data._scale.second << std::endl;
        std::cout << "-------------------------------------" << std::endl;

    if (mousePos.first >= _data._pos.first && mousePos.first <= _data._pos.first + (_data._texture.getSize().x * _data._scale.first) && mousePos.second >= _data._pos.second && mousePos.second <= _data._pos.second + (_data._texture.getSize().y * _data._scale.second))
        std::cout << "prout" << std::endl;
    else 
        std::cout << "pas prout" << std::endl;
    return _data.isClicked;
}
