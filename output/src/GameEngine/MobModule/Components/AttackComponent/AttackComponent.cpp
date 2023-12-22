/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#include "AttackComponent.hpp"

#include <stdexcept>

Engine::MobModule::Components::AttackComponent::AttackComponent(
    AttackComponentData data) {
    _value = data;
}

Engine::MobModule::Components::AttackComponent::~AttackComponent(){};

void Engine::MobModule::Components::AttackComponent::execute() {}

Engine::MobModule::Components::AttackComponentData &
    Engine::MobModule::Components::AttackComponent::getValue() {
    return (_value);
}

void Engine::MobModule::Components::AttackComponent::setValue(
    AttackComponentData value) {
    _value = value;
}

void Engine::MobModule::Components::AttackComponent::setDamage(int value) {
    _value.Damage = value;
}

void Engine::MobModule::Components::AttackComponent::setRange(float value) {
    _value.Range = value;
}

void Engine::MobModule::Components::AttackComponent::setAttackSpeed(
    float value) {
    _value.AttackSpeed = value;
}

void Engine::MobModule::Components::AttackComponent::setAttackType(int value) {
    _value.AttackType = value;
}

int Engine::MobModule::Components::AttackComponent::getDamage() const {
    return (_value.Damage);
}

float Engine::MobModule::Components::AttackComponent::getRange() const {
    return (_value.Range);
}

float Engine::MobModule::Components::AttackComponent::getAttackSpeed() const {
    return (_value.AttackSpeed);
}

int Engine::MobModule::Components::AttackComponent::getAttackType() const {
    return (_value.AttackType);
}
