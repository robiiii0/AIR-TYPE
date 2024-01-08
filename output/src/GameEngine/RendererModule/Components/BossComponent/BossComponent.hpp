/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#ifndef BOSSCOMPONENT_HPP_
#define BOSSCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.hpp"
#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct BossData {
                    Engine::Entity::Component::GenericComponents::Vector2f pos;
                    Engine::Entity::Component::GenericComponents::Vector2f
                                scale;
                    sf::Color   color;
                    float       rotation;
                    sf::IntRect rect;
            };

            class BossComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    BossComponent(
                        BossData    &value,
                        sf::Texture &texture);  // TODO changer le std::string
                    ~BossComponent();

                    void execute() override;

                    // Sprite
                    void          setRotation(float rotation);
                    void          setScale(float x, float y);
                    void          setTextureRect();
                    void          setPosition(float x, float y);
                    sf::Drawable &getDrawable() override;

                protected:
                private:
                    Engine::Entity::Component::GenericComponents::Vector2f _pos;
                    Engine::Entity::Component::GenericComponents::Vector2f
                                _scale;
                    sf::Color   _color;
                    float       _rotation;
                    sf::Sprite  _sprite;
                    sf::IntRect _rect;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !BOSSCOMPONENT_HPP_ */
