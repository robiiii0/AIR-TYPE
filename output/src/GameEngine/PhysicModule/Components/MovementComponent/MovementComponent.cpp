/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#include "MovementComponent.hpp"

Engine::Physic::Components::MovementComponent::MovementComponent(
    Engine::Physic::Components::MovementData &data) :
    _data(data) {
    _maxVelocity = data.maxVelocity;
    _velocity = data.velocity;
    _acceleration = data.acceleration;
}

// Engine::Physic::Components::MovementComponent::MovementComponent(
//     Vector2f acceleration, Vector2f velocity, float maxVelocity) :
//     _acceleration(acceleration),
//     _velocity(velocity),
//     _maxVelocity(maxVelocity),
//     _data({acceleration, velocity, maxVelocity}) {}

Engine::Physic::Components::MovementComponent::~MovementComponent() {}

void Engine::Physic::Components::MovementComponent::execute() {
    //  this->updateVelocity();
}

void Engine::Physic::Components::MovementComponent::setAcceleration(
    Vector2f &acceleration) {
    _acceleration = acceleration;
}

void Engine::Physic::Components::MovementComponent::setVelocity(
    Vector2f &velocity) {
    _velocity = velocity;
}

void Engine::Physic::Components::MovementComponent::setMaxVelocity(
    float maxVelocity) {
    _maxVelocity = maxVelocity;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::MovementComponent::getAcceleration() const {
    return _acceleration;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::MovementComponent::getVelocity() const {
    return _velocity;
}

float Engine::Physic::Components::MovementComponent::getMaxVelocity() const {
    return _maxVelocity;
}

void Engine::Physic::Components::MovementComponent::updateVelocity(float dt) {
    if (_velocity.x < _maxVelocity || _velocity.y < _maxVelocity) {
        _velocity.y += _acceleration.y * dt;
        _velocity.x += _acceleration.x * dt;
    }
}

void Engine::Physic::Components::MovementComponent::normalize() {
    float length = sqrt(_acceleration.x * _acceleration.x +
                        _acceleration.y * _acceleration.y);

    if (length != 0) {
        _acceleration.x = _acceleration.x / length;
        _acceleration.y = _acceleration.y / length;
    }
}
