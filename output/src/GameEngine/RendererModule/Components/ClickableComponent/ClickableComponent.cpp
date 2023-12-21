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
    ClickableData &value, sf::Texture &texture) :
    _data(value) {
    _isHovered = false;
    _isClicked = false;
    _sprite.setTexture(texture);
    _sprite.setTexture(texture);
    _sprite.setPosition(_data.pos);
    _sprite.setScale(_data.scale);
    _sprite.setColor(_data.color);
    _sprite.setRotation(_data.rotation);
    std::cout << "ClickableCompoent created" << std::endl;
}

sf::Vector2f Engine::RendererModule::Components::ClickableComponent::getPos()
    const {
    return _data.pos;
}

sf::Drawable &
    Engine::RendererModule::Components::ClickableComponent::getDrawable() {
    return _sprite;
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
    return _isHovered;
}

bool Engine::RendererModule::Components::ClickableComponent::isClicked(
    std::pair<float, float> mousePos) const {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "mousePos: " << mousePos.first << ", " << mousePos.second
              << std::endl;
    std::cout << "pos: " << _data.pos.x << ", " << _data.pos.y << std::endl;
    //    std::cout << "getSpriteSize"
    //              << _data._texture.getSize().x * _data._scale.first << ", "
    //              << _data._texture.getSize().y * _data._scale.second <<
    //              std::endl;
    std::cout << "-------------------------------------" << std::endl;

    sf::FloatRect bounds = _sprite.getGlobalBounds();

    if (bounds.contains(mousePos.first, mousePos.second)) {
        std::cout << "prout" << std::endl;
        return true;
    } else {
        std::cout << "pas prout" << std::endl;
        return false;
    }
    //    if (mousePos.first >= _data.pos.x &&
    //        mousePos.first <= _data.pos.x + (_sprite.getSize().x *
    //                                              _data._scale.first) &&
    //        mousePos.second >= _data.pos.y &&
    //        mousePos.second <= _data.pos.y + (_data._texture.getSize().y *
    //                                                _data._scale.second))
    //        std::cout << "prout" << std::endl;
    //    else
    //        std::cout << "pas prout" << std::endl;
    return _isClicked;
}
