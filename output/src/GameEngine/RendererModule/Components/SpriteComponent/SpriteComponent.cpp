/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#include "SpriteComponent.hpp"

#include <stdexcept>

template<typename T>
Engine::RendererModule::Components::SpriteComponent<T>::SpriteComponent(
    T value) {
    _component_name = "SpriteComponent";
    if (value.type() != typeid(std::string))
        throw std::runtime_error("SpriteComponent: value is not a string");
    else {
        _path = value;
        if (!_texture.loadFromFile(_path))
            throw std::runtime_error("SpriteComponent: texture not found");
        _sprite.setTexture(_texture);
        _ptr = value;
    }
}

template<typename T>
Engine::RendererModule::Components::SpriteComponent<T>::~SpriteComponent() {}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::execute() {}

template<typename T>
T& Engine::RendererModule::Components::SpriteComponent<T>::get() {
    return (_ptr);
}

template<typename T>
std::string Engine::RendererModule::Components::SpriteComponent<T>::getName()
    const {
    return (_component_name);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setRotation(
    float rotation) {
    _sprite.setRotation(rotation);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setScale(float x,
                                                                   float y) {
    _sprite.setScale(x, y);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setOrigin(float x,
                                                                    float y) {
    _sprite.setOrigin(x, y);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setRepeated(
    bool repeated) {
    _texture.setRepeated(repeated);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setSmooth(
    bool smooth) {
    _texture.setSmooth(smooth);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setPosition(float x,
                                                                      float y) {
    _sprite.setPosition(x, y);
}

template<typename T>
void Engine::RendererModule::Components::SpriteComponent<T>::setTextureRect(
    const sf::IntRect& rect) {
    _sprite.setTextureRect(rect);
}
