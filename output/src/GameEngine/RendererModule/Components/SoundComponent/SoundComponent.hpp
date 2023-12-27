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
                    bool        loop = false;
                    bool        play = false;
                    float       volume = 50;
            };

            class SoundComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    SoundComponent(SoundData &value);
                    ~SoundComponent();
                    void       execute() override;
                    SoundData &get();
                    void       play();
                    void       pause();
                    void       stop();

                    void setLoop(bool loop);

                    void  setVolume(float volume);
                    float getVolume() const;

                protected:
                private:
                    std::uint32_t _id;
                    SoundData     _data;
                    sf::Music     _sound;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif  // AIR_TYPE_SOUND_COMPONENT_HPP
