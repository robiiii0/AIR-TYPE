/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** DefenseComponent
*/

#include "DefenseComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::DefenseComponent::DefenseComponent(int data) {
    _value = data;
}

Engine::MobModule::Components::DefenseComponent::~DefenseComponent() = default;

void Engine::MobModule::Components::DefenseComponent::execute() {}

int &Engine::MobModule::Components::DefenseComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::DefenseComponent::setValue(int value) {
    _value = value;
}
