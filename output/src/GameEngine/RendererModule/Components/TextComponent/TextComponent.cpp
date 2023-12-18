/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#include "TextComponent.hpp"

Engine::RendererModule::Components::TextComponent::TextComponent(
    Engine::RendererModule::Components::TextData &value) : _data(value) {
    _text.setString(_data.text);
    _text.setFont(_data.font);
    _text.setColor(_data.color);
    _text.setPosition(_data.position);
    _text.setScale(_data.scale);
    _text.setRotation(_data.rotation);
}

Engine::RendererModule::Components::TextComponent::~TextComponent() {}

void Engine::RendererModule::Components::TextComponent::execute() {}

bool Engine::RendererModule::Components::TextComponent::isDrawable() const {
    return true;
}

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
    _text.setColor(_data.color);
    _text.setPosition(_data.position);
    _text.setScale(_data.scale);
    _text.setRotation(_data.rotation);
}

Engine::RendererModule::Components::TextData
    Engine::RendererModule::Components::TextComponent::getTextData() const {
    return _data;
}
