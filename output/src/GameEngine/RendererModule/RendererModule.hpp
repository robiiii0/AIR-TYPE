/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** RendererModule
*/

#ifndef RENDERERMODULE_HPP_
#define RENDERERMODULE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../EntityManager/EntityManager.hpp"
#include "Components/SpriteComponent/SpriteComponent.hpp"
#include "Components/AnimationComponent/AnimationComponent.hpp"
#include "Components/TextComponent/TextComponent.hpp"
#include "Components/ClickableComponent/ClickableComponent.hpp"


namespace Engine {
    namespace RendererModule {
        class RendererModule {
            public:
                RendererModule();
                ~RendererModule();
                void              init(int width, int height, std::string title,
                                       int framerate);
                void              update();
                void              render(Engine::Entity::EntityManager &entityManager, uint32_t id);
                sf::RenderWindow& getWindow();

            protected:
            private:
                sf::RenderWindow _window;
                sf::Event        _event;  // a enlever si on a un event manager
        };
    };  // namespace RendererModule
};      // namespace Engine

#endif /* !RENDERERMODULE_HPP_ */
