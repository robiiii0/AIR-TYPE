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
                    bool                    isAnimated;
                    sf::IntRect             rect;
                    sf::Clock               _clock;
            };

            class parallaxComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    parallaxComponent(parallaxData &value,
                                      sf::Texture  &texture);
                    ~parallaxComponent();

                    sf::Drawable &getDrawable() override;
                    void          execute() override;
                    void          setRotation(float rotation);
                    void          setScale(float x, float y);
                    void          setOrigin(float x, float y);
                    void          setTextureRect(const sf::IntRect &rect);
                    void          setPosition(float x, float y);
                    void          setMovement(float x, float y);
                    void          runParallax();
                    void          Animation();

                private:
                    parallaxData _data;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !PARALLAXCOMPONENT_HPP_ */
