/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** SpriteComponent
*/

#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include <SFML/Graphics.hpp>

namespace Engine {
    namespace RendererModule {
        namespace Components {
            class SpriteComponent : public Engine::Entity::Component::AComponent {
                public:
                    SpriteComponent(std::uint32_t id,
                                    std::string component_name, std::any value);
                    ~SpriteComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;


                    // Sprite
                    void setRotation(float rotation);
                    void setScale(float x, float y);
                    void setOrigin(float x, float y);
                    void setTextureRect(const sf::IntRect& rect);

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
                    std::any      _ptr;
            };
        };
    };
};

#endif /* !SPRITECOMPONENT_HPP_ */
