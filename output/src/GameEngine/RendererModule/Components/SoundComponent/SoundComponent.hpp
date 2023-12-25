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
                    bool      loop;
                    float     volume;
                    std::string path;
            };

            class SoundComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    SoundComponent(SoundData &value);
                    ~SoundComponent();

                    void execute() override;
                    sf::Drawable &getDrawable() override;

                    //                // Sound
                    //                void setVolume(float volume);
                    //                void setLoop(bool loop);
                    //                void play();
                    //                void pause();
                    //                void stop();

                protected:
                private:
                    SoundData &_data;
                    sf::Music _sound;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif  // AIR_TYPE_SOUND_COMPONENT_HPP
