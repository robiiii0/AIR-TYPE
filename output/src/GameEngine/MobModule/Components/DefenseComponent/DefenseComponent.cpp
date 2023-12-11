/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** DefenseComponent
*/

#include "DefenseComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::MobModule::Components::DefenseComponent<T>::DefenseComponent(int data) {
    if (typeid(T) != typeid(int))
        throw std::invalid_argument("T is not an int");
    else {
        _component_name = "DefenseComponent";
        _data = data;
    }
}

template <typename T>
Engine::MobModule::Components::DefenseComponent<T>::~DefenseComponent() = default;

template <typename T>
void Engine::MobModule::Components::DefenseComponent<T>::execute() {}

template <typename T>
std::string Engine::MobModule::Components::DefenseComponent<T>::getName() const {
    return _component_name;
}
