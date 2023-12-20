/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** parallaxComponent
*/

#ifndef PARALLAXCOMPONENT_HPP_
#define PARALLAXCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct parallaxData {
                    sf::Texture             _texture;
                    sf::Sprite              _sprite;
                    std::string             _name;
                    std::string             _path;
                    std::string             _ptr;
                    std::pair<float, float> _pos;
                    std::pair<float, float> _scale;
                    std::uint32_t           _id;
            };

            class parallaxComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    parallaxComponent(std::vector<parallaxData> &value);
                    ~parallaxComponent();
                    void          execute() override;
                    sf::Drawable &getDrawable(parallaxData _data);

                protected:
                private:
                    std::vector<parallaxData> &_data;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !PARALLAXCOMPONENT_HPP_ */
