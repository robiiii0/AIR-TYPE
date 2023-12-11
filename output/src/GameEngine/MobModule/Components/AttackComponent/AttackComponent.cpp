/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#include "AttackComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::AttackComponent::AttackComponent(
    std::any value) {
    if (value.type() == typeid(int)) {
        _component_name = "AttackComponent";
        _damage = std::any_cast<int>(value);
        _ptr = value;
    } else
        throw std::runtime_error("AttackComponent value is not int");
}

Engine::MobModule::Components::AttackComponent::~AttackComponent(){};

void Engine::MobModule::Components::AttackComponent::execute() {}

std::any& Engine::MobModule::Components::AttackComponent::get() { return _ptr; }

std::string Engine::MobModule::Components::AttackComponent::getName() const {
    return _component_name;
}
