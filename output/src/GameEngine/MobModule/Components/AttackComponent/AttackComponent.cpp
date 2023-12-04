/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#include "AttackComponent.hpp"

// TODO: gestion d'erreur si value n'est pas un int 

Engine::MobModule::Components::AttackComponent::AttackComponent(
    std::uint32_t id, std::string component_name, std::any value) {
    _id = id;
    _component_name = "AttackComponent";
    _damage = std::any_cast<int>(value);
}

Engine::MobModule::Components::AttackComponent::~AttackComponent() = default;

void Engine::MobModule::Components::AttackComponent::execute() {}

std::any& Engine::MobModule::Components::AttackComponent::get() {
    _ptr = _damage;
    return _ptr;
}

std::string Engine::MobModule::Components::AttackComponent::getName() const {
    return _component_name;
}
