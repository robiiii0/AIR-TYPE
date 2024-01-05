/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#include "TextComponent.hpp"

Engine::RendererModule::Components::TextComponent::TextComponent(
    Engine::RendererModule::Components::TextData &value) :
    _data(value) {
    _text.setString(_data.text);
    _text.setFont(_data.font);
    _text.setFillColor(_data.color);
    _text.setScale(_data.scale.x, _data.scale.y);
    sf::FloatRect text_bounds = _text.getGlobalBounds();
    _text.setPosition({_data.position.x - text_bounds.width / 2,
                       _data.position.y - text_bounds.height / 2});
    _text.setRotation(_data.rotation);
    _relative_pos.x =
        _data.position.x -
        text_bounds.width / 2;  // ? Same question as in SpriteComponent.cpp
    _relative_pos.y = _data.position.y - text_bounds.height / 2;
}

Engine::RendererModule::Components::TextComponent::~TextComponent() {}

void Engine::RendererModule::Components::TextComponent::execute() {}

sf::Drawable &Engine::RendererModule::Components::TextComponent::getDrawable() {
    return _text;
}

void Engine::RendererModule::Components::TextComponent::setTextData(
    TextData &data) {
    _data.text = data.text;
    _data.font = data.font;
    _data.color = data.color;
    _data.position = data.position;
    _data.scale = data.scale;
    _data.rotation = data.rotation;
    _text.setString(_data.text);
    _text.setFont(_data.font);
    _text.setFillColor(_data.color);
    _text.setPosition(_data.position.x, _data.position.y);
    _text.setScale(_data.scale.x, _data.scale.y);
    _text.setRotation(_data.rotation);
}

void Engine::RendererModule::Components::TextComponent::setPosition(float x,
                                                                    float y) {
    _text.setPosition(x + _relative_pos.x, y + _relative_pos.y);
}

Engine::RendererModule::Components::TextData
    Engine::RendererModule::Components::TextComponent::getTextData() const {
    return _data;
}

sf::Text Engine::RendererModule::Components::TextComponent::getText() const {
    return _text;
}
