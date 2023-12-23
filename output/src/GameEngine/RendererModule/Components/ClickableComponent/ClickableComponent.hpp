/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ClickableComponent
*/

#ifndef CLICKABLECOMPONENT_HPP_
#define CLICKABLECOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct ClickableData {
                    sf::Sprite   _sprite;
                    sf::Vector2f pos;
                    sf::Vector2f scale;
                    sf::Color    color;
                    float        rotation;
            };

            class ClickableComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    ClickableComponent(ClickableData &value,
                                       sf::Texture   &texture);
                    ~ClickableComponent();
                    void          execute() override;
                    sf::Drawable &getDrawable() override;
                    void          update();
                    sf::Vector2f  getPos() const;
                    bool          isHovered(std::pair<float, float> mousePos) const;
                    bool isClicked(std::pair<float, float> mousePos) const;

                protected:
                private:
                    ClickableData &_data;
                    sf::Sprite     _sprite;
                    bool           _isHovered;
                    bool           _isClicked;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !CLICKABLECOMPONENT_HPP_ */
