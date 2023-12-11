/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** VelocityComponent
*/

#include "VelocityComponent.hpp"

template<typename T>
Engine::Physic::Components::VelocityComponent<T>::VelocityComponent(T data) {
    if (value.type() == typeid(T)) {
        _component_name = "VelocityComponent";
        this->data = data;
    }
}

template<typename T>
Engine::Physic::Components::VelocityComponent<T>::~VelocityComponent() {}

template<typename T>
void Engine::Physic::Components::VelocityComponent<T>::execute() {}

template<typename T>
std::string Engine::Physic::Components::VelocityComponent<T>::getName() const {
    return (_component_name);
}

template<typename T>
void Engine::Physic::Components::VelocityComponent<T>::setVelocity(
    std::pair<float, float> velocity) {
    _velocity = velocity;
    data = _velocity;
}
