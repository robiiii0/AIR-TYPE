/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AnimationComponent
*/

#include "AnimationComponent.hpp"

Engine::RendererModule::Components::AnimationComponent::AnimationComponent(
    std::any value) {
    _component_name = "AnimationComponent";
    if (value.type() != typeid(sf::IntRect))
        throw std::runtime_error("AnimationComponent: value is not a string");
    else {
        _rect = std::any_cast<sf::IntRect>(value);
        _ptr = value;
    }
}

Engine::RendererModule::Components::AnimationComponent::~AnimationComponent() {}

void Engine::RendererModule::Components::AnimationComponent::execute() {}

std::any& Engine::RendererModule::Components::AnimationComponent::get() {
    return (_ptr);
}

std::string Engine::RendererModule::Components::AnimationComponent::getName()
    const {
    return (_component_name);
}

sf::IntRect Engine::RendererModule::Components::AnimationComponent::getRect()
    const {
    return (_rect);
}

void Engine::RendererModule::Components::AnimationComponent::update(
    float deltaTime, int nbFrame, int rectBase) {
    _time += deltaTime;
    if (_time >= 0.1f) {
        _rect.left += _rect.width;
        if (_rect.left >= nbFrame * _rect.width) _rect.left = rectBase;
        _time = 0;
    }
}
