/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** SoundEnumType
*/

#ifndef SOUNDENUMTYPE_HPP_
#define SOUNDENUMTYPE_HPP_

namespace Engine {
    namespace RendererModule {
        namespace Components {
            /*
             * @brief Enum for the sound type
             */
            enum SoundEnumType {
                MAIN_MUSIC,
                CLICK_SOUND,
                SHOOT_SOUND,
                EXPLOSION_SOUND,
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !SOUNDENUMTYPE_HPP_ */
