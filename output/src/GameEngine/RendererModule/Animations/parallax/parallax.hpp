/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** parallaxComponent
*/

#ifndef PARALLAXCOMPONENT_HPP_
#define PARALLAXCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct parallaxData {
                    sf::Sprite              _sprite;
                    std::string             _name;
                    std::pair<float, float> _pos;
                    std::pair<float, float> _scale;
                    std::pair<float, float> _movement;
            };

            class parallaxComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    parallaxComponent(parallaxData &value, sf::Texture &texture);
                    ~parallaxComponent();

                    sf::Drawable &getDrawable() override;
                    void execute() override;
                    void setRotation(parallaxData _data, float rotation);
                    void setScale(parallaxData _data, float x, float y);
                    void setOrigin(parallaxData _data, float x, float y);
                    void setTextureRect(parallaxData       _data,
                                        const sf::IntRect &rect);
                    void setPosition(parallaxData _data, float x, float y);
                    void setMovement(parallaxData _data, float x, float y);
                    void runParallax();

                protected:
                private:
                    parallaxData &_data;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !PARALLAXCOMPONENT_HPP_ */
