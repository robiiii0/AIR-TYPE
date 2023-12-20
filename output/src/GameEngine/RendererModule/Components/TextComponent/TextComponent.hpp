/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#ifndef TEXTCOMPONENT_HPP_
#define TEXTCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../IRendererComponent/IRendererComponent.hpp"

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

            class TextComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    TextComponent(TextData &value);
                    ~TextComponent();
                    void          execute() override;
                    sf::Drawable &getDrawable() override;
                    void          setTextData(TextData &data);
                    TextData      getTextData() const;

                protected:
                private:
                    TextData &_data;
                    sf::Text  _text;
            };
        }  // namespace Components
    }      // namespace RendererModule
}  // namespace Engine

#endif /* !TEXTCOMPONENT_HPP_ */
