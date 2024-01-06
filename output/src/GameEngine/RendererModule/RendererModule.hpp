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
#include "Animations/Parallax/Parallax.hpp"
#include "Components/AnimationComponent/AnimationComponent.hpp"
#include "Components/ClickableComponent/ClickableComponent.hpp"
#include "Components/ClickableComponent/RoundedClickableComponent.hpp"
#include "Components/InputComponent/InputComponent.hpp"
#include "Components/SoundComponent/SoundComponent.hpp"
#include "Components/SpriteComponent/SpriteComponent.hpp"
#include "Components/EnemyComponent/EnemyComponent.hpp"
#include "Components/TextComponent/TextComponent.hpp"
#include "IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        class RendererModule {
            public:
                RendererModule();
                ~RendererModule();
                void init(int width, int height, std::string title,
                          int framerate);
                void update(Engine::Entity::EntityManager &entityManager,
                            std::vector<uint32_t>          id_list);
                void render(Engine::Entity::EntityManager &entityManager,
                            std::vector<uint32_t>          id_list);
                sf::RenderWindow &getWindow();
                int               UpdateForServer(
                                  Engine::Entity::EntityManager &entityManager,
                                  std::vector<uint32_t>          id_list);

            protected:
            private:
                sf::RenderWindow _window;
                sf::Event        _event;
        };
    };  // namespace RendererModule
};      // namespace Engine

#endif /* !RENDERERMODULE_HPP_ */
