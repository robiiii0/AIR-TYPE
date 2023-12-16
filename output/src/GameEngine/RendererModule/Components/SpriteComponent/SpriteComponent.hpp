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
            template<typename T>
            class SpriteComponent :
                public Engine::Entity::Component::AComponent<T> {
                public:
                    SpriteComponent(T value);
                    ~SpriteComponent();
                    void        execute() override;
                    T&   get() override;
                    std::string getName() const override;

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
                    std::string   _component_name;
                    std::string   _path;
                    T      _ptr;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !SPRITECOMPONENT_HPP_ */
