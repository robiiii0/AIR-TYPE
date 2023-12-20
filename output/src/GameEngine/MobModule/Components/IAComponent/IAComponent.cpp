/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** IAComponent
*/

#include "IAComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::IAComponent::IAComponent(int data) {
    _value = data;
}

Engine::MobModule::Components::IAComponent::~IAComponent() {}

void Engine::MobModule::Components::IAComponent::execute() {}

int &Engine::MobModule::Components::IAComponent::getValue() { return (_value); }

void Engine::MobModule::Components::IAComponent::setValue(int value) {
    _value = value;
}
