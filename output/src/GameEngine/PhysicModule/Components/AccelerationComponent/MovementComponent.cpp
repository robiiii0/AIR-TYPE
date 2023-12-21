/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#include "AccelerationComponent.hpp"

Engine::Physic::Components::AccelerationComponent::AccelerationComponent(
    Engine::Physic::Components::MovementData &data) :
    _data(data) {}

Engine::Physic::Components::AccelerationComponent::~AccelerationComponent() {}

void Engine::Physic::Components::AccelerationComponent::execute() {
      this->updateVelocity();
}

void Engine::Physic::Components::AccelerationComponent::setAcceleration(
    Vector2f &acceleration) {
    this->_data.acceleration = acceleration;
}

void Engine::Physic::Components::AccelerationComponent::setVelocity(
    Vector2f &velocity) {
    this->_data.velocity = velocity;
}

Engine::Physic::Components::Vector2f
    Engine::Physic::Components::AccelerationComponent::getAcceleration() const {
    return (this->_data.acceleration);
}

Engine::Physic::Components::Vector2f
    Engine::Physic::Components::AccelerationComponent::getVelocity() const {
    return (this->_data.velocity);
}

//TODO : calculate Velocity: velocity += acceleration * time
void Engine::Physic::Components::AccelerationComponent::updateVelocity() {
    this->_data.velocity.y += this->_data.acceleration.y; //TODO : multiply by delta time
    this->_data.velocity.x += this->_data.acceleration.x;
}
