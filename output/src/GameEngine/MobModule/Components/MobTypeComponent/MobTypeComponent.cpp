/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MobTypeComponent
*/

#include "MobTypeComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::MobTypeComponent::MobTypeComponent(int data) {
      _value = data;
}

Engine::MobModule::Components::MobTypeComponent::~MobTypeComponent() =
    default;

void Engine::MobModule::Components::MobTypeComponent::execute() {}

int &Engine::MobModule::Components::MobTypeComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::MobTypeComponent::setValue(int value) {
    _value = value;
}
