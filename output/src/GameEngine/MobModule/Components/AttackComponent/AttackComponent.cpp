/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#include "AttackComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::AttackComponent::AttackComponent(int data) {
    _value = data;
}

Engine::MobModule::Components::AttackComponent::~AttackComponent(){};

void Engine::MobModule::Components::AttackComponent::execute() {}

int &Engine::MobModule::Components::AttackComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::AttackComponent::setValue(int value) {
    _value = value;
}
