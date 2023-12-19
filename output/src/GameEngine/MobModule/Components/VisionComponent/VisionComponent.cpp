/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** VisionComponent
*/

#include "VisionComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::VisionComponent::VisionComponent(int data) {}

Engine::MobModule::Components::VisionComponent::~VisionComponent() {}

void Engine::MobModule::Components::VisionComponent::execute() {}

int &Engine::MobModule::Components::VisionComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::VisionComponent::setValue(int value) {
    _value = value;
}
