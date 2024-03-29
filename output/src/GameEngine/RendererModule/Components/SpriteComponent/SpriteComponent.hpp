/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.hpp"
#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct SpriteData {
                    Engine::Entity::Component::GenericComponents::Vector2f pos;
                    Engine::Entity::Component::GenericComponents::Vector2f
                              scale;
                    sf::Color color;
                    float     rotation;
                    bool      Playable;
                    uint32_t  id;
            };

            class SpriteComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    SpriteComponent(SpriteData &value, sf::Texture &texture);
                    ~SpriteComponent();

                    void     execute() override;
                    uint32_t getId();
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
                    uint32_t   _id;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !SPRITECOMPONENT_HPP_ */
