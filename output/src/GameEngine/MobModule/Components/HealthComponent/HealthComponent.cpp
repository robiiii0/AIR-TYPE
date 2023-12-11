/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** HealthComponent
*/

#include "HealthComponent.hpp"

#include <stdexcept>

template<typename T>
Engine::MobModule::Components::HealthComponent<T>::HealthComponent(
    HealthComponentData data) {
    if (typeid(T) != typeid(int))
        throw std::invalid_argument("T is not an int");
    else {
        _component_name = "HealthComponent";
        _data = data;
    }
}

template<typename T>
Engine::MobModule::Components::HealthComponent<T>::~HealthComponent() {}

template<typename T>
void Engine::MobModule::Components::HealthComponent<T>::execute() {}

template<typename T>
std::string Engine::MobModule::Components::HealthComponent<T>::getName() const {
    return _component_name;
}
