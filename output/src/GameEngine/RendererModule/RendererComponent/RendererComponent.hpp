/*
** EPITECH PROJECT, 2023
** R_type
** File description:
** RendererComponent
*/

#ifndef RENDERERCOMPONENT_HPP_
#define RENDERERCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        class IRendererComponent :
            public Engine::Entity::Component::AComponent {
                virtual bool          IsDrawable() const = 0;
                virtual sf::Drawable &Drawables() = 0;
        };
    }  // namespace RendererModule
}  // namespace Engine

#endif /* !RENDERERCOMPONENT_HPP_ */
