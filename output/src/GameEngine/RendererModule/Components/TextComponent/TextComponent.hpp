/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#ifndef TEXTCOMPONENT_HPP_
#define TEXTCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct TextData {
                    std::string  text;
                    sf::Font    &font;
                    sf::Color    color;
                    sf::Vector2f position;
                    sf::Vector2f scale;
                    float        rotation;
            };

            template<typename T>
            class TextComponent : public Engine::Entity::Component::AComponent {
                public:
                    TextComponent(T value);
                    ~TextComponent();
                    void          execute() override;
                    std::string   getName() const override;
                    sf::Drawable &getDrawable() override;

                protected:
                private:
                    T        _data;
                    sf::Text _text;
            };
        }  // namespace Components
    }      // namespace RendererModule
}  // namespace Engine

#endif /* !TEXTCOMPONENT_HPP_ */
