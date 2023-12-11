/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** StateComponent
*/

#include "StateComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::MobModule::Components::StateComponent<T>::StateComponent(bool data) {
    if (typeid(T) != typeid(bool))
        throw std::invalid_argument("T is not a bool");
    else {
        _component_name = "StateComponent";
        _data = data;
    }
}

template <typename T>
Engine::MobModule::Components::StateComponent<T>::~StateComponent() {}

template <typename T>
void Engine::MobModule::Components::StateComponent<T>::execute() {}

template <typename T>
std::string Engine::MobModule::Components::StateComponent<T>::getName() const {
    return _component_name;
}
