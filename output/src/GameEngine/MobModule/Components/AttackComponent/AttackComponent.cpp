/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#include "AttackComponent.hpp"

#include <stdexcept>

template<typename T>
Engine::MobModule::Components::AttackComponent<T>::AttackComponent(int data) {
    if (typeid(T) != typeid(int))
        throw std::invalid_argument("T is not an int");
    else
        _component_name = "AttackComponent";
    _data = data;
}

template<typename T>
Engine::MobModule::Components::AttackComponent<T>::~AttackComponent(){};

template<typename T>
void Engine::MobModule::Components::AttackComponent<T>::execute() {}

template<typename T>
std::string Engine::MobModule::Components::AttackComponent<T>::getName() const {
    return _component_name;
}
