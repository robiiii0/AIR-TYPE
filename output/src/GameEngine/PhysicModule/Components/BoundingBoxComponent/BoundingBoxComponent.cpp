/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** BoundingBoxComponent
*/

#include "BoundingBoxComponent.hpp"

Engine::Physic::Components::BoundingBoxComponent::BoundingBoxComponent(
    HitboxData &data) :
    _data(data) {}

Engine::Physic::Components::BoundingBoxComponent::~BoundingBoxComponent() {}

void Engine::Physic::Components::BoundingBoxComponent::execute() {}

void Engine::Physic::Components::BoundingBoxComponent::setBoundingBox(
    HitboxData &data) {
    _data = data;
}

Engine::Physic::Components::HitboxData &
    Engine::Physic::Components::BoundingBoxComponent::getBoundingBox() {
    return _data;
}
