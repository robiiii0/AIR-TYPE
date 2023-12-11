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

namespace Engine {
    namespace RendererModule {
        class RendererModule {
            public:
                RendererModule();
                ~RendererModule();
                void init();
                void update();
                void render();

            protected:
            private:
                sf::RenderWindow _window;
                sf::Event        _event;  // a enlever si on a un event manager
        };
    };  // namespace RendererModule
};      // namespace Engine

#endif /* !RENDERERMODULE_HPP_ */
