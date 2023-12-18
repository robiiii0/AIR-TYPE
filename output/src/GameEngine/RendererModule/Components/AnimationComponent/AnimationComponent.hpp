/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AnimationComponent
*/

#ifndef ANIMATIONCOMPONENT_HPP_
#define ANIMATIONCOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct AnimationData {
                    float time;
                    sf::IntRect rect;
                    int height;
                    int width;
                    int pos_x;
                    int pos_y;
            };

            class AnimationComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    AnimationComponent(AnimationData value);
                    ~AnimationComponent();
                    void         execute() override;
                    AnimationData& get();

                    void update(float deltaTime, int nbFrame, int rectBase);

                    sf::IntRect getRect() const;

                private:
                    std::uint32_t _id;
                    AnimationData _data;
                    float _time;
            };
        };  // namespace Components
    };      // namespace RendererModule
}  // namespace Engine

#endif /* !ANIMATIONCOMPONENT_HPP_ */
