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
    SoundData &value, std::string path) :
    _data(value) {
    if (!_data.sound.openFromFile(path))
        std::cout << "cant load: " << path << std::endl;
    _data.sound.setLoop(_data.loop);
    _data.sound.setVolume(_data.volume);
    std::cout << "sound created" << std::endl;
}

Engine::RendererModule::Components::SoundComponent::~SoundComponent() {
    _data.sound.stop();
}
