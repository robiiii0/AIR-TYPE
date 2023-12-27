/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** BoundingBoxComponent
*/

#include "BoundingBoxComponent.hpp"

Engine::Physic::Components::BoundingBoxComponent::BoundingBoxComponent(
    HitboxData &data) :
    _data(data) {
    _pos = _data.pos;
    _size = _data.size;
}

Engine::Physic::Components::BoundingBoxComponent::~BoundingBoxComponent() {}

void Engine::Physic::Components::BoundingBoxComponent::execute() {}

void Engine::Physic::Components::BoundingBoxComponent::setBoundingBox(
    HitboxData &data) {
    _pos = data.pos;
    _size = data.size;
}

Engine::Physic::Components::HitboxData &
    Engine::Physic::Components::BoundingBoxComponent::getBoundingBox() {
    return _data;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::BoundingBoxComponent::getPos() const {
    return _pos;
}

Engine::Physic::Vector2f
    Engine::Physic::Components::BoundingBoxComponent::getSize() const {
    return _size;
}

void Engine::Physic::Components::BoundingBoxComponent::setPos(Vector2f pos) {
    _pos = pos;
}

void Engine::Physic::Components::BoundingBoxComponent::setSize(Vector2f size) {
    _size = size;
}

bool Engine::Physic::Components::BoundingBoxComponent::operator==(
    const BoundingBoxComponent &other) const {
    if (other._pos.x > this->_pos.x &&
        other._pos.x < this->_pos.x + this->_size.x &&
        other._pos.x + other._size.x > this->_pos.x &&
        other._pos.x + other._size.x < this->_pos.x + this->_size.x &&
        other._pos.y > this->_pos.y &&
        other._pos.y < this->_pos.y + this->_size.y &&
        other._pos.y + other._size.y > this->_pos.y &&
        other._pos.y + other._size.y < this->_pos.y + this->_size.y) {
        return true;
    }
    return false;
}
