/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** ClientSoundsManagement
*/

#include "../Client.hpp"

void Client::LoadSound(std::string paths, bool loop, bool play, float volume) {
    Engine::RendererModule::Components::SoundData data = {paths, loop, play,
                                                          volume};

    std::shared_ptr<Engine::RendererModule::Components::SoundComponent>
        soundComponent = std::make_shared<
            Engine::RendererModule::Components::SoundComponent>(data);

    _sounds.push_back(soundComponent);
}
