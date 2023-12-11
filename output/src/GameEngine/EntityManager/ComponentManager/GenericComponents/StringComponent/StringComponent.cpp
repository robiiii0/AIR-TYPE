/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** StringComponent
*/

#include "StringComponent.hpp"

template <typename T>
Engine::Entity::Component::GenericComponents::StringComponent<T>::StringComponent(std::string value) {
    _component_name = "StringComponent";
    _value = value;
}

template <typename T>
Engine::Entity::Component::GenericComponents::StringComponent<T>::
    ~StringComponent() {}

template <typename T>
void Engine::Entity::Component::GenericComponents::StringComponent<T>::execute() {}

template <typename T>
std::string Engine::Entity::Component::GenericComponents::StringComponent<T>::getName()
        const {
    return _component_name;
}
