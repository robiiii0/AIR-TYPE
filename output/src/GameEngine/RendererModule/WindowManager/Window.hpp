/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** WindowComponent
*/

#ifndef WINDOWCOMPONENT_HPP_
#define WINDOWCOMPONENT_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace RendererModule {
        class Window {
            public:
                Window();
                ~Window();

                void setSize(sf::Vector2u size, sf::Window window);
                void setFramerateLimit(unsigned int limit, sf::Window window);
                void setVerticalSyncEnabled(bool enabled, sf::Window window);
                void setTitle(std::string title, sf::Window window);
                void setIcon(sf::Image icon, sf::Window window);
                void setMouseCursorVisible(bool visible, sf::Window window);
                void setMouseCursorGrabbed(bool grabbed, sf::Window window);
                void setKeyRepeatEnabled(bool enabled, sf::Window window);
                void requestFocus(sf::Window window);

                sf::Vector2u     getSize(sf::Window window) const;
                bool             isFocus(sf::Window window) const;
                sf::WindowHandle getSystemHandle(sf::Window window) const;

            protected:
            private:
        };
    };  // namespace RendererModule
};      // namespace Engine

#endif /* !WINDOWCOMPONENT_HPP_ */
