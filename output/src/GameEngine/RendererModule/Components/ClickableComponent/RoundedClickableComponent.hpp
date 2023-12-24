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
                    sf::Color               _color;
            };

            class RoundedClickableComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    RoundedClickableComponent(
                        RoundedClickableData &value,
                        std::function<void()> func = []() {});

                    ~RoundedClickableComponent();

                    void          execute() override;
                    sf::Drawable &getDrawable() override;
                    void          update();
                    sf::Vector2f  getPos() const;
                    bool          isHovered(std::pair<float, float> mousePos);
                    bool          isClicked(std::pair<float, float> mousePos);

                protected:
                private:
                    RoundedClickableData &_data;
                    sf::RectangleShape    _buttonShape;
                    std::function<void()> _func = []() {};
                    bool                  _isHovered;
                    bool                  _isClicked;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif  // AIR_TYPE_ROUNDEDCLICKABLECOMPONENT_H
