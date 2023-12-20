/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ClickableComponent
*/

#ifndef CLICKABLECOMPONENT_HPP_
#define CLICKABLECOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct ClickableData {
                    bool                    isHovered;
                    bool                    isClicked;
                    sf::Texture             _texture;
                    sf::Sprite              _sprite;
                    std::string             _name;
                    std::string             _path;
                    std::string             _ptr;
                    std::pair<float, float> _pos;
                    std::pair<float, float> _scale;
                    std::uint32_t           _id;
            };

            class ClickableComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    ClickableComponent(ClickableData &value);
                    ~ClickableComponent();
                    void          execute() override;
                    sf::Drawable &getDrawable();
                    void          update();
                    bool          isHovered() const;
                    bool isClicked(std::pair<float, float> mousePos) const;

                protected:
                private:
                    ClickableData &_data;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !CLICKABLECOMPONENT_HPP_ */
