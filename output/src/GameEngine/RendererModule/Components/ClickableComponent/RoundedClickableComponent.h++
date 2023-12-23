//
// Created by Robin Chabert on 23/12/2023.
//

#ifndef AIR_TYPE_ROUNDEDCLICKABLECOMPONENT_H
#define AIR_TYPE_ROUNDEDCLICKABLECOMPONENT_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {

            struct RoundedClickableData {
                std::pair<float, float> _pos;
                std::pair<float, float> _size;
                const std::string& buttonText;
                sf::RectangleShape buttonShape;
                sf::Text buttonTextObj;
                sf::Font font;
            };

            class RoundedClickableComponent : public Engine::RendererModule::IRendererComponent {
            public:
                RoundedClickableComponent(RoundedClickableData &value);
                ~RoundedClickableComponent();

                void execute() override;
                sf::Drawable &getDrawable() override;
                void update();
                sf::Vector2f getPos() const;
                bool isHovered(std::pair<float, float> mousePos) const;
                bool isClicked(std::pair<float, float> mousePos) const;


            protected:
            private:
                RoundedClickableData &_data;
                sf::Sprite _sprite;
                bool _isHovered;
                bool _isClicked;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engi

#endif //AIR_TYPE_ROUNDEDCLICKABLECOMPONENT_H
