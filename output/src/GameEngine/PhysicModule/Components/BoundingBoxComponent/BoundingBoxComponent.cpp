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

bool Engine::Physic::Components::BoundingBoxComponent::operator==(
    const BoundingBoxComponent &other) const {
    if (this->_data.pos
            .x<other._data.pos.x + other._data.size.x &&this->_data.pos.x +
               this->_data.size.x>
                other._data.pos.x &&
        this->_data.pos
            .y<other._data.pos.y + other._data.size.y &&this->_data.pos.y +
               this->_data.size.y>
                other._data.pos.y) {
        return true;
    }
    return false;
}
