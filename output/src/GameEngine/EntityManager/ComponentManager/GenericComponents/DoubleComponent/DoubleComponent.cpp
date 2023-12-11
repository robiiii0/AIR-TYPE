/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** DoubleComponent
*/

#include "DoubleComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::Entity::Component::GenericComponents::DoubleComponent<T>::DoubleComponent(double data) {
    if (typeid(T) != typeid(double))
        throw std::invalid_argument("T is not a double");
    else {
        _component_name = "DoubleComponent";
        _data = data;
    }
}

template <typename T>
Engine::Entity::Component::GenericComponents::DoubleComponent<T>::~DoubleComponent() {}

template <typename T>
void Engine::Entity::Component::GenericComponents::DoubleComponent<T>::execute() {}

template <typename T>
std::string Engine::Entity::Component::GenericComponents::DoubleComponent<T>::getName() const {
    return _component_name;
}
