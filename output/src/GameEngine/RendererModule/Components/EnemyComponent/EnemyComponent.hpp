/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.hpp"
#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct EnemyData {
                    Engine::Entity::Component::GenericComponents::Vector2f pos;
                    Engine::Entity::Component::GenericComponents::Vector2f
                              scale;
                    sf::Color color;
                    float     rotation;
                    bool      Playable;
            };

            class EnemyComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    EnemyComponent(
                        EnemyData   &value,
                        sf::Texture &texture);  // TODO changer le std::string
                                                // pour le sprite c'est pas bien
                    ~EnemyComponent();

                    void execute() override;

                    // Sprite
                    void          setRotation(float rotation);
                    void          setScale(float x, float y);
                    void          setTextureRect(const sf::IntRect &rect);
                    void          setPosition(float x, float y);
                    void          handleEvent(int key);
                    sf::Drawable &getDrawable() override;

                protected:
                private:
                    Engine::Entity::Component::GenericComponents::Vector2f _pos;
                    Engine::Entity::Component::GenericComponents::Vector2f
                               _scale;
                    sf::Color  _color;
                    float      _rotation;
                    bool       _Playable;
                    sf::Sprite _sprite;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !ENEMYCOMPONENT_HPP_ */
