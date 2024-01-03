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
    _text.setString("Default value.");
    _text.setFont(font);
    _text.setScale(_data.scale);
    sf::FloatRect bounds = _text.getLocalBounds();
    _text.setPosition(
        {_data.pos.x - bounds.width / 2, _data.pos.y - bounds.height / 2});
    _text.setFillColor(sf::Color::White);
    _text.setCharacterSize(30);
    _isClicked = false;
    _isHovered = false;
    _str = "";
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

void Engine::RendererModule::Components::InputComponent::handleEvent(
    sf::Event event) {
    if (event.type == sf::Event::TextEntered && _isClicked) {
        if (_str.size() < 20 && event.text.unicode != 8)
            _str += static_cast<char>(event.text.unicode);
        else if (event.text.unicode == 8 && !_str.empty())
            _str.pop_back();
        _text.setString(_str);
    }
}

bool Engine::RendererModule::Components::InputComponent::isHovered(
    std::pair<float, float> mousePos) {}

bool Engine::RendererModule::Components::InputComponent::isClicked(
    std::pair<float, float> mousePos) {
    sf::FloatRect Bounds = _text.getGlobalBounds();

    Bounds.left -= 100.0f;
    Bounds.top -= 100.0f;
    Bounds.width += 100.0f;
    Bounds.height += 100.0f;

    if (Bounds.contains(mousePos.first, mousePos.second)) {
        _isClicked = true;
        return true;
    } else {
        _isClicked = false;
        return false;
    }
}
