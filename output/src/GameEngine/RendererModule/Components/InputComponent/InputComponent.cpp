/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

Engine::RendererModule::Components::InputComponent::InputComponent(
    InputData &data, sf::Font &font) :
    _data(data) {
    _text.setString("_data.text");
    _text.setFont(font);
    _text.setScale(_data.scale);
    sf::FloatRect bounds = _text.getLocalBounds();
    _text.setPosition({_data.pos.x - bounds.width / 2,
                       _data.pos.y - bounds.height / 2});
    _text.setFillColor(sf::Color::White);
    _text.setCharacterSize(30);
    _isClicked = false;
    _isHovered = false;
    std::cout << "InputComponent created" << std::endl;
}

Engine::RendererModule::Components::InputComponent::~InputComponent() {}

void Engine::RendererModule::Components::InputComponent::execute() {}

sf::Drawable &
    Engine::RendererModule::Components::InputComponent::getDrawable() {
    return _text;
}

void Engine::RendererModule::Components::InputComponent::update() {}

sf::Vector2f Engine::RendererModule::Components::InputComponent::getPos()
    const {
    return _text.getPosition();
}

bool Engine::RendererModule::Components::InputComponent::getClicked() {
    return _isClicked;
}

bool Engine::RendererModule::Components::InputComponent::isHovered(
    std::pair<float, float> mousePos) {}

bool Engine::RendererModule::Components::InputComponent::isClicked(
    std::pair<float, float> mousePos) {
    sf::FloatRect bounds = _text.getGlobalBounds();

    if (bounds.contains(mousePos.first, mousePos.second)) {
        _isClicked = true;
        std::cout << "Clicked" << std::endl;
        return true;
    } else {
        _isClicked = false;
        return false;
    }
}
