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


void Engine::RendererModule::Components::parallaxComponent::setRotation(
        parallaxData _data, float rotation) { _data._sprite.setRotation(rotation); }


void Engine::RendererModule::Components::parallaxComponent::setScale(
        parallaxData _data, float x, float y) { _data._sprite.setScale(x, y); }

    
void Engine::RendererModule::Components::parallaxComponent::setOrigin(
        parallaxData _data, float x, float y) { _data._sprite.setOrigin(x, y); }


void Engine::RendererModule::Components::parallaxComponent::setTextureRect(
        parallaxData _data, const sf::IntRect &rect) { _data._sprite.setTextureRect(rect); }


void Engine::RendererModule::Components::parallaxComponent::setPosition(
        parallaxData _data, float x, float y) { _data._sprite.setPosition(x, y); }


void Engine::RendererModule::Components::parallaxComponent::setMovement(
        parallaxData _data, float x, float y) { _data._movement = std::make_pair(x, y); }
    
// void Engine::RendererModule::Components::parallaxComponent::runParallax() {
//     for (auto &i : _data) {
//         i._sprite.move(i._movement.first, i._movement.second);
//     }
// }