/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ClickableComponent
*/

#include "ClickableComponent.hpp"

#include <stdexcept>

template<typename T>
Engine::RendererModule::Components::ClickableComponent<T>::ClickableComponent(
    T value) {
    if (typeid(T) != = typeid(ClickableData))
        throw std::invalid_argument("TextComponent: value is not a TextData");
    else {
    }
}

template<typename T>
Engine::RendererModule::Components::ClickableComponent<
    T>::~ClickableComponent() {}

template<typename T>
void Engine::RendererModule::Components::ClickableComponent<T>::execute() {}

template<typename T>
std::string Engine::RendererModule::Components::ClickableComponent<T>::getName()
    const {
    return _component_name;
}

template<typename T>
void Engine::RendererModule::Components::ClickableComponent<T>::update() {}

template<typename T>
bool Engine::RendererModule::Components::ClickableComponent<T>::isHovered()
    const {
    return _data.isHovered;
}

template<typename T>
bool Engine::RendererModule::Components::ClickableComponent<T>::isClicked()
    const {
    return _data.isClicked;
}
