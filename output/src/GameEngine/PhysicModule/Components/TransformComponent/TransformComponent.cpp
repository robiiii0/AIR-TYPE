/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** PositionComponet
*/

#include "TransformComponent.hpp"
#include <iostream>

Engine::Physic::Components::TransformComponent::TransformComponent(
    TransformData &data) :
    _data(data) {
        _x = 120.0;
        _y = data.pos.y;
    }

Engine::Physic::Components::TransformComponent::~TransformComponent() {}

void Engine::Physic::Components::TransformComponent::execute() {}

void Engine::Physic::Components::TransformComponent::setTransform(
    TransformData &data) {
    _data = data;
}

void Engine::Physic::Components::TransformComponent::setPos(Vector2f pos) {
    _pos = pos;
}

void Engine::Physic::Components::TransformComponent::setPos(float x, float y) {
    std::cout << "test" << std::endl;
    _x = 100.0;
    // std::cout << _x << std::endl;
    // this->x = x + y;
    // _pos.x = x + this->x;
    // _pos.y = y;
}

void Engine::Physic::Components::TransformComponent::setScale(Vector2f scale) {
    _scale = scale;
}

void Engine::Physic::Components::TransformComponent::setRotation(
    float rotation) {
    _rotation = rotation;
}

Engine::Physic::Components::TransformData &
    Engine::Physic::Components::TransformComponent::getTransform() {
    return _data;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::TransformComponent::getPos() const {
    std::cout << "teest" << std::endl;
    return _pos;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::TransformComponent::getScale() const {
    return _scale;
}

float Engine::Physic::Components::TransformComponent::getRotation() const {
    return _rotation;
}
