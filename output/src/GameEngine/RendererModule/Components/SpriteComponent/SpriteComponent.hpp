/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            class SpriteComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    SpriteComponent(std::string value); //TODO changer le std::string pour le sprite c'est pas bien
                    ~SpriteComponent();
                    void        execute() override;
                    std::string&   get();

                    // Sprite
                    void setRotation(float rotation);
                    void setScale(float x, float y);
                    void setOrigin(float x, float y);
                    void setTextureRect(const sf::IntRect& rect);
                    void setPosition(float x, float y);

                    // Texture
                    void setRepeated(bool repeated);
                    void setSmooth(bool smooth);

                protected:
                private:
                    sf::Texture   _texture;
                    sf::Sprite    _sprite;
                    std::uint32_t _id;
                    std::string   _path;
                    std::string      _ptr;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !SPRITECOMPONENT_HPP_ */
