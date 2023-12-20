/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** parallax
*/

#include "parallax.hpp"

Engine::RendererModule::Components::parallaxComponent::parallaxComponent(
    std::vector<parallaxData> &value) :
    _data(value) {}

Engine::RendererModule::Components::parallaxComponent::~parallaxComponent() {}

void Engine::RendererModule::Components::parallaxComponent::execute() {}

sf::Drawable &Engine::RendererModule::Components::parallaxComponent::getDrawable(
        parallaxData _data) { return _data._sprite; }


