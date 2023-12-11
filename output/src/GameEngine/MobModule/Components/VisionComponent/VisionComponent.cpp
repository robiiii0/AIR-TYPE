/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** VisionComponent
*/

#include "VisionComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::MobModule::Components::VisionComponent<T>::VisionComponent(
    int data) {
    if (typeid(T) != typeid(int))
        throw std::invalid_argument("T is not an int");
    else {
        _component_name = "VisionComponent";
        _data = data;
    }
}

template <typename T>
Engine::MobModule::Components::VisionComponent<T>::~VisionComponent() {}

template <typename T>
void Engine::MobModule::Components::VisionComponent<T>::execute() {}

template <typename T>
std::string Engine::MobModule::Components::VisionComponent<T>::getName() const {
    return _component_name;
}
