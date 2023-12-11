/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** IAComponent
*/

#include "IAComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::MobModule::Components::IAComponent<T>::IAComponent(int data) {
    if (typeid(T) != typeid(int))
        throw std::invalid_argument("T is not an int");
    else {
        _component_name = "IAComponent";
        _data = data;
    }
}

template <typename T>
Engine::MobModule::Components::IAComponent<T>::~IAComponent() {}

template <typename T>
void Engine::MobModule::Components::IAComponent<T>::execute() {}

template <typename T>
std::string Engine::MobModule::Components::IAComponent<T>::getName() const {
    return _component_name;
}
