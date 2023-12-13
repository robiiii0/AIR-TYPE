/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MassComponent
*/

#include "MassComponent.hpp"

template<typename T>
Engine::Physic::Components::MassComponent<T>::MassComponent(T data) {
    if (value.type() == typeid(T)) {
        _component_name = "MassComponent";
        this->data = data;
    }
}

template<typename T>
Engine::Physic::Components::MassComponent<T>::~MassComponent() {}

template<typename T>
void Engine::Physic::Components::MassComponent<T>::execute() {}

template<typename T>
std::string Engine::Physic::Components::MassComponent<T>::getName() const {
    return (_component_name);
}

template<typename T>
void Engine::Physic::Components::MassComponent<T>::setMass(float mass) {
    _mass = mass;
    this->data = _mass;
}
