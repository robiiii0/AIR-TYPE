/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** SoundComponent
*/

#include "SoundComponent.hpp"

Engine::RendererModule::Components::SoundComponent::SoundComponent(
    SoundData &value) {
    _data = value;
    if (!_sound.openFromFile(_data.path))
        std::cout << "cant load: " << _data.path << std::endl;
    _sound.setLoop(_data.loop);
    _sound.setVolume(_data.volume);
    if (_data.play) {
        _sound.play();
        std::cout << "play: " << _data.path << std::endl;
    } 
}

Engine::RendererModule::Components::SoundComponent::~SoundComponent() {
    _sound.stop();
}

void Engine::RendererModule::Components::SoundComponent::execute() {}

Engine::RendererModule::Components::SoundData &
    Engine::RendererModule::Components::SoundComponent::get() {
    return _data;
}

void Engine::RendererModule::Components::SoundComponent::play() {
    _sound.play();
}

void Engine::RendererModule::Components::SoundComponent::pause() {
    _sound.pause();
}

void Engine::RendererModule::Components::SoundComponent::stop() {
    _sound.stop();
}

void Engine::RendererModule::Components::SoundComponent::setLoop(bool loop) {
    _sound.setLoop(loop);
}

void Engine::RendererModule::Components::SoundComponent::setVolume(
    float volume) {
    _sound.setVolume(volume);
    _data.volume = volume;
}

float Engine::RendererModule::Components::SoundComponent::getVolume() const {
    return _data.volume;
}
