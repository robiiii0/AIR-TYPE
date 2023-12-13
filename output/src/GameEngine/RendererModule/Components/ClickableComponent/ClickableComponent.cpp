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
        _data.isHovered = false;
        _data.isClicked = false;
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
void Engine::RendererModule::Components::ClickableComponent<T>::update() {
    // TODO: MousePosition and Entity position in parameters ?
    // Get MousePosition
    // Get Entity Position

    // Check if MousePosition is in Entity Position
    // Update _data.isHovered

    // Check if Mouse is clicked
    // Update _data.isClicked
}

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
