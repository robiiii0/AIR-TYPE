/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#include "AccelerationComponent.hpp"

template<typename T>
Engine::Physic::Components::AccelerationComponent<T>::AccelerationComponent(
    T data) {
    if (data.type() == typeid(T)) {
        _component_name = "AccelerationComponent";
        this->data = data;
    }
}

template<typename T>
Engine::Physic::Components::AccelerationComponent<T>::~AccelerationComponent() {
}

template<typename T>
void Engine::Physic::Components::AccelerationComponent<T>::execute() {}

template<typename T>
std::string Engine::Physic::Components::AccelerationComponent<T>::getName()
    const {
    return (_component_name);
}

template<typename T>
void Engine::Physic::Components::AccelerationComponent<T>::setAcceleration(
    std::pair<float, float> acceleration) {
    _acceleration = acceleration;
    data = _acceleration;
}
