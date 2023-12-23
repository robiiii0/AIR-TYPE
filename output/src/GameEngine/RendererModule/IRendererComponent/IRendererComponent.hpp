/*
** EPITECH PROJECT, 2023
** R_type
** File description:
** IRendererComponent
*/

#ifndef RENDERERCOMPONENT_HPP_
#define RENDERERCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        class IRendererComponent :
            public Engine::Entity::Component::AComponent {
            public:
                virtual sf::Drawable &getDrawable() = 0;
        };
    }  // namespace RendererModule
}  // namespace Engine

#endif /* !RENDERERCOMPONENT_HPP_ */
