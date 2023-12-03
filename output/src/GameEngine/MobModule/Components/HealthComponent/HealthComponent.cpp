/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** HealthComponent
*/

#include "HealthComponent.hpp"

Engine::MobModule::Components::HealthComponent::HealthComponent(
    std::uint32_t id, std::string component_name, std::any value)
{
    _id = id;
    _component_name = "HealthComponent";

    if (value.type() == typeid(std::pair<int, int>)) {
        auto pairValue = std::any_cast<std::pair<int, int>>(value);
        _health = pairValue.first;
        _maxHealth = pairValue.second;
    } //else
        // throw std::runtime_error("HealthComponent value is not an int");
}

Engine::MobModule::Components::HealthComponent::~HealthComponent() {}

void Engine::MobModule::Components::HealthComponent::execute() {}

std::any& Engine::MobModule::Components::HealthComponent::get() {
    _ptr = std::make_any<std::pair<int, int>>(std::make_pair(_health, _maxHealth));
    return _ptr;
}

std::string Engine::MobModule::Components::HealthComponent::getName() const {
    return _component_name;
}
