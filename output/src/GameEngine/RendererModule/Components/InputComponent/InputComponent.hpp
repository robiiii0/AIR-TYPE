/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct InputData {
                    sf::Vector2f pos;
                    sf::Vector2f scale;
                    sf::Color    color;
                    float        rotation;
            };

            class InputComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    InputComponent(InputData &data, sf::Font &font);
                    ~InputComponent();
                    void          execute() override;
                    sf::Drawable &getDrawable() override;
                    void          update();

                    bool        getClicked();

                    void handleEvent(sf::Event event);

                    sf::Vector2f getPos() const;
                    bool         isHovered(std::pair<float, float> mousePos);
                    bool         isClicked(std::pair<float, float> mousePos);

                protected:
                private:
                    InputData &_data;
                    sf::Text            _text;
                    std::string         _str;
                    bool                _isHovered;
                    bool                _isClicked;
            };
        }  // namespace Components
    }      // namespace RendererModule
}  // namespace Engine

#endif  // INPUTCOMPONENT_HPP
