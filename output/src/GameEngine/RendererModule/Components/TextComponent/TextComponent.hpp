/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#ifndef TEXTCOMPONENT_HPP_
#define TEXTCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../../EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.hpp"
#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct TextData {
                    std::string text;
                    sf::Font   &font;
                    sf::Color   color;
                    Engine::Entity::Component::GenericComponents::Vector2f
                        position;
                    Engine::Entity::Component::GenericComponents::Vector2f
                          scale;
                    float rotation;
            };

            class TextComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    TextComponent(TextData &value);
                    ~TextComponent();
                    void          execute() override;
                    sf::Drawable &getDrawable() override;
                    void          setTextData(TextData &data);
                    void          setPosition(float x, float y);
                    TextData      getTextData() const;
                    sf::Text      getText() const;

                protected:
                private:
                    TextData &_data;
                    sf::Text  _text;
                    Engine::Entity::Component::GenericComponents::Vector2f
                        _relative_pos;
            };
        }  // namespace Components
    }      // namespace RendererModule
}  // namespace Engine

#endif /* !TEXTCOMPONENT_HPP_ */
