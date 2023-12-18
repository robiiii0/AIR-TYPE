/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AnimationComponent
*/

#include "AnimationComponent.hpp"

Engine::RendererModule::Components::AnimationComponent::AnimationComponent(
    AnimationData value) {
    _data = value;
}

Engine::RendererModule::Components::AnimationComponent::~AnimationComponent() {}

void Engine::RendererModule::Components::AnimationComponent::execute() {}

Engine::RendererModule::Components::AnimationData& Engine::RendererModule::Components::AnimationComponent::get() {
    return (_data);
}


sf::IntRect Engine::RendererModule::Components::AnimationComponent::getRect()
    const {
    return (_data.rect);
}

void Engine::RendererModule::Components::AnimationComponent::update(
    float deltaTime, int nbFrame, int rectBase) {
    _time += deltaTime;
    if (_time >= _data.time) {
        _data.rect.left += _data.rect.width;
        if (_data.rect.left >= nbFrame * _data.rect.width) _data.rect.left = rectBase;
        _time = 0;
    }
}
