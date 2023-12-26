/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** SoundComponent
*/

#ifndef AIR_TYPE_SOUND_COMPONENT_HPP
#define AIR_TYPE_SOUND_COMPONENT_HPP

#include <SFML/Audio.hpp>

#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct SoundData {
                std::string path;
                bool      loop;
                bool     play;
                float     volume;
            };

            class SoundComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    SoundComponent(SoundData &value);
                    ~SoundComponent();
                    void execute() override;
                    SoundData& get();
                    void play();
                    void pause();
                    void stop();

                    //                // Sound
                    //                void setVolume(float volume);
                    //                void setLoop(bool loop);
                    //                void play();
                    //                void pause();
                    //                void stop();

                protected:
                private:
                    std::uint32_t _id;
                    SoundData &_data;
                    sf::Music _sound;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif  // AIR_TYPE_SOUND_COMPONENT_HPP
