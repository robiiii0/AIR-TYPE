/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#include "AttackComponent.hpp"

#include <stdexcept>

template <typename T>
Engine::MobModule::Components::AttackComponent<T>::AttackComponent(
    std::any value) {
    if (value.type() == typeid(int)) {
        _component_name = "AttackComponent";
        _damage = std::any_cast<int>(value);
        _ptr = value;
    } else
        throw std::runtime_error("AttackComponent value is not int");
}

template <typename T>
Engine::MobModule::Components::AttackComponent::~AttackComponent(){};

template <typename T>
void Engine::MobModule::Components::AttackComponent::execute() {}

template <typename T>
std::string Engine::MobModule::Components::AttackComponent::getName() const {
    return _component_name;
}
