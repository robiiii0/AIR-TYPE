//
// Created by aymericchaverot on 26/12/23.
//

#include "Vector2fComponent.hpp"

Engine::Entity::Component::GenericComponents::Vector2fComponent::
    Vector2fComponent(Vector2f &data) {
    _value.x = data.x;
    _value.y = data.y;
}

Engine::Entity::Component::GenericComponents::Vector2fComponent::
    ~Vector2fComponent() {}

void Engine::Entity::Component::GenericComponents::Vector2fComponent::setValue(
    Vector2f &value) {
    _value.x = value.x;
    _value.y = value.y;
}

Engine::Entity::Component::GenericComponents::Vector2f
    Engine::Entity::Component::GenericComponents::Vector2fComponent::getValue()
        const {
    return _value;
}

void Engine::Entity::Component::GenericComponents::Vector2fComponent::
    execute() {}
