/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AnimationComponent
*/

#ifndef ANIMATIONCOMPONENT_HPP_
#define ANIMATIONCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            class AnimationComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    AnimationComponent(std::uint32_t id,
                                       std::string   component_name,
                                       std::any      value);
                    ~AnimationComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                    void update(float deltaTime, int nbFrame, int rectBase);

                    sf::IntRect getRect() const;

                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    std::any      _ptr;
                    sf::IntRect   _rect;
                    float         _time;

            };
        };  // namespace Components
    };      // namespace RendererModule
}  // namespace Engine

#endif /* !ANIMATIONCOMPONENT_HPP_ */
