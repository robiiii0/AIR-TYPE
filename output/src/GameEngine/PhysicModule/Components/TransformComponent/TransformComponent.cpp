/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** PositionComponet
*/

#include "TransformComponent.hpp"

Engine::Physic::Components::TransformComponent::TransformComponent(
    TransformData &data) :
    _data(data) {}

Engine::Physic::Components::TransformComponent::~TransformComponent() {}

void Engine::Physic::Components::TransformComponent::execute() {}

void Engine::Physic::Components::TransformComponent::setTransform(
    TransformData &data) {
    _data = data;
}

void Engine::Physic::Components::TransformComponent::setPos(Vector2f pos) {
    _data.pos = pos;
}

void Engine::Physic::Components::TransformComponent::setScale(Vector2f scale) {
    _data.scale = scale;
}

void Engine::Physic::Components::TransformComponent::setRotation(
    float rotation) {
    _data.rotation = rotation;
}

Engine::Physic::Components::TransformData &
    Engine::Physic::Components::TransformComponent::getTransform() {
    return _data;
}
