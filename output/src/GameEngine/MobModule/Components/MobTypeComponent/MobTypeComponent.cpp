/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MobTypeComponent
*/

#include "MobTypeComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::MobModule::Components::MobTypeComponent<T>::MobTypeComponent(
    int data) {
    if (typeid(T) != typeid(int))
        throw std::invalid_argument("T is not an int");
    else {
        _component_name = "MobTypeComponent";
        _data = data;
    }
}

template <typename T>
Engine::MobModule::Components::MobTypeComponent<T>::~MobTypeComponent() = default;

template <typename T>
void Engine::MobModule::Components::MobTypeComponent<T>::execute() {}

template <typename T>
std::string Engine::MobModule::Components::MobTypeComponent<T>::getName() const {
    return _component_name;
}
