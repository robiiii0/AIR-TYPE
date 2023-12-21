/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#include "MovementComponent.hpp"

Engine::Physic::Components::MovementComponent::MovementComponent(
    Engine::Physic::Components::MovementData &data) :
    _data(data) {}

Engine::Physic::Components::MovementComponent::~MovementComponent() {}

void Engine::Physic::Components::MovementComponent::execute() {
    this->updateVelocity();
}

void Engine::Physic::Components::MovementComponent::setAcceleration(
    Vector2f &acceleration) {
    this->_data.acceleration = acceleration;
}

void Engine::Physic::Components::MovementComponent::setVelocity(
    Vector2f &velocity) {
    this->_data.velocity = velocity;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::MovementComponent::getAcceleration() const {
    return (this->_data.acceleration);
}

Engine::Physic::Vector2f
    Engine::Physic::Components::MovementComponent::getVelocity() const {
    return (this->_data.velocity);
}

// TODO : calculate Velocity: velocity += acceleration * time
void Engine::Physic::Components::MovementComponent::updateVelocity() {
    this->_data.velocity.y +=
        this->_data.acceleration.y;  // TODO : multiply by delta time
    this->_data.velocity.x += this->_data.acceleration.x;
}
