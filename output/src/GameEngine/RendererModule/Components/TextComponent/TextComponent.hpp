/*
** EPITECH PROJECT, 2023
** output
** File description:
** TextComponent
*/

#ifndef TEXTCOMPONENT_HPP_
#define TEXTCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../RendererComponent/RendererComponent.hpp"

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
            class TextComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    TextComponent(T value);
                    ~TextComponent();
                    void          execute() override;
                    std::string   getName() const override;
                    bool          isDrawable() const override;
                    sf::Drawable &getDrawable() override;
                    void          setTextData(TextData data);
                    TextData      getTextData() const;

                protected:
                private:
                    T        _data;
                    sf::Text _text;
            };
        }  // namespace Components
    }      // namespace RendererModule
}  // namespace Engine

#endif /* !TEXTCOMPONENT_HPP_ */