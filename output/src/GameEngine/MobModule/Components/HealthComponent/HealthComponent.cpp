/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** HealthComponent
*/

#include "HealthComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::HealthComponent::HealthComponent(
    std::uint32_t id, std::string component_name, std::any value) {
    if (value.type() == typeid(HealthComponentData)) {
        _id = id;
        _component_name = "HealthComponent";
        auto true_value = std::any_cast<HealthComponentData>(value);
        _data = true_value;
    } else
        throw std::runtime_error("HealthComponent value is not pair<int,int>");
}

Engine::MobModule::Components::HealthComponent::~HealthComponent() {}

void Engine::MobModule::Components::HealthComponent::execute() {}

std::any& Engine::MobModule::Components::HealthComponent::get() {
    _ptr = std::make_any<HealthComponentData>(_data);
    return _ptr;
}

std::string Engine::MobModule::Components::HealthComponent::getName() const {
    return _component_name;
}
