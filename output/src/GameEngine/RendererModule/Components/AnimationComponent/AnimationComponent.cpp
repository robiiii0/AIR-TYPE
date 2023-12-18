/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AnimationComponent
*/

#include "AnimationComponent.hpp"
template<typename T>
Engine::RendererModule::Components::AnimationComponent<T>::AnimationComponent(
    T value) {
    _component_name = "AnimationComponent";
    if (value.type() != typeid(sf::IntRect))
        throw std::runtime_error("AnimationComponent: value is not a string");
    else {
        _rect = value;
        _ptr = &value;
    }
}

template<typename T>
Engine::RendererModule::Components::AnimationComponent<T>::~AnimationComponent() {}

template<typename T>
void Engine::RendererModule::Components::AnimationComponent<T>::execute() {}

template<typename T>
T& Engine::RendererModule::Components::AnimationComponent<T>::get() {
    return (_ptr);
}

template<typename T>
std::string Engine::RendererModule::Components::AnimationComponent<T>::getName()
    const {
    return (_component_name);
}

template<typename T>
sf::IntRect Engine::RendererModule::Components::AnimationComponent<T>::getRect()
    const {
    return (_rect);
}

template<typename T>
void Engine::RendererModule::Components::AnimationComponent<T>::update(
    float deltaTime, int nbFrame, int rectBase) {
    _time += deltaTime;
    if (_time >= 0.1f) {
        _rect.left += _rect.width;
        if (_rect.left >= nbFrame * _rect.width) _rect.left = rectBase;
        _time = 0;
    }
}
