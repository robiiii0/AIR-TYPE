/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** StateComponent
*/

#include "StateComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::StateComponent::StateComponent(bool data) {
    _value = data;
}

Engine::MobModule::Components::StateComponent::~StateComponent() {}

void Engine::MobModule::Components::StateComponent::execute() {}

bool &Engine::MobModule::Components::StateComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::StateComponent::setValue(bool value) {
    _value = value;
}
