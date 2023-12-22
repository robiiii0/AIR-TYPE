/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** HealthComponent
*/

#include "HealthComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::HealthComponent::HealthComponent(
    HealthComponentData data) {
    _value = data;
}

Engine::MobModule::Components::HealthComponent::~HealthComponent() {}

void Engine::MobModule::Components::HealthComponent::execute() {}

Engine::MobModule::Components::HealthComponentData &
    Engine::MobModule::Components::HealthComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::HealthComponent::setValue(
    HealthComponentData value) {
    _value = value;
}

void Engine::MobModule::Components::HealthComponent::setHealth(int value) {
    _value.health = value;
}

void Engine::MobModule::Components::HealthComponent::setMaxHealth(int value) {
    _value.maxHealth = value;
}

int Engine::MobModule::Components::HealthComponent::getHealth() const {
    return (_value.health);
}

int Engine::MobModule::Components::HealthComponent::getMaxHealth() const {
    return (_value.maxHealth);
}

