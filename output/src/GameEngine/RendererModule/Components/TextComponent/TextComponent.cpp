/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#include "TextComponent.hpp"

template<typename T>
Engine::RendererModule::Components::TextComponent<T>::TextComponent(T value) {
    if (typeid(T) != typeid(TextData))
        throw std::runtime_error("TextComponent: value is not a TextData");
    _data = value;
    _text.setString(_data.text);
    _text.setFont(_data.font);
    _text.setColor(_data.color);
    _text.setPosition(_data.position);
    _text.setScale(_data.scale);
    _text.setRotation(_data.rotation);
}

template<typename T>
Engine::RendererModule::Components::TextComponent<T>::~TextComponent() {}

template<typename T>
void Engine::RendererModule::Components::TextComponent<T>::execute() {}

template<typename T>
std::string Engine::RendererModule::Components::TextComponent<T>::getName()
    const {
    return "RendererTextComponent";
}

template<typename T>
sf::Drawable &
    Engine::RendererModule::Components::TextComponent<T>::getDrawable() {
    return _text;
}
