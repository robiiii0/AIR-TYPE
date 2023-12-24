//
// Created by Robin Chabert on 23/12/2023.
//

#include "RoundedClickableComponent.hpp"


Engine::RendererModule::Components::RoundedClickableComponent::RoundedClickableComponent(RoundedClickableData &value, std::function<void()> func) : _data(value), _isHovered(false), _isClicked(false), _func(func) {
                sf::RectangleShape shape(sf::Vector2f(value._size.first, value._size.second));
                _buttonShape = shape;
                _buttonShape.setPosition(_data._pos.first, _data._pos.second);
                _buttonShape.setSize(sf::Vector2f(_data._size.first, _data._size.second));
                _buttonShape.setFillColor(_data._color);
                _buttonShape.setOutlineColor(sf::Color::Black);
                _buttonShape.setOutlineThickness(2.0f);
                std::cout << "ClickableComponent created" << std::endl;
}

Engine::RendererModule::Components::RoundedClickableComponent::~RoundedClickableComponent() {}

void Engine::RendererModule::Components::RoundedClickableComponent::execute() {}

sf::Drawable &Engine::RendererModule::Components::RoundedClickableComponent::getDrawable() {
    return _buttonShape;
}

void Engine::RendererModule::Components::RoundedClickableComponent::update() {

}

sf::Vector2f Engine::RendererModule::Components::RoundedClickableComponent::getPos() const {
}

bool Engine::RendererModule::Components::RoundedClickableComponent::isHovered(
    std::pair<float, float> mousePos) {
    sf::FloatRect bounds = _buttonShape.getGlobalBounds();

    if (bounds.contains(mousePos.first, mousePos.second)) {
        _buttonShape.setFillColor(sf::Color::Red);
        return true;
    } else {
        _buttonShape.setFillColor(_data._color);
        return false;
    }
    return _isClicked;
}

bool Engine::RendererModule::Components::RoundedClickableComponent::isClicked(
    std::pair<float, float> mousePos) {
    sf::FloatRect bounds = _buttonShape.getGlobalBounds();

    if (bounds.contains(mousePos.first, mousePos.second)) {
        _func();
        return true;
    } else {
        return false;
    }
    return _isClicked;
}