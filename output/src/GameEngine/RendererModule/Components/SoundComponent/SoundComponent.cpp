/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** SoundComponent
*/

#include "SoundComponent.hpp"

#include <iostream>
#include <stdexcept>

Engine::RendererModule::Components::SoundComponent::SoundComponent(
    SoundData &value) :
    _data(value) {
    if (!_sound.openFromFile(_data.path))
        std::cout << "cant load: " << _data.path << std::endl;
    _sound.setLoop(_data.loop);
    _sound.setVolume(_data.volume);
    _sound.play();
    std::cout << "sound created" << std::endl;
}

Engine::RendererModule::Components::SoundComponent::~SoundComponent() {
    _sound.stop();
}

void Engine::RendererModule::Components::SoundComponent::execute() {
    _sound.play();
}

sf::Drawable &Engine::RendererModule::Components::SoundComponent::getDrawable() {
    sf::Sprite drawable_text;
    return drawable_text;
}
