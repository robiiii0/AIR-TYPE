/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#ifndef ACCELERATIONCOMPONENT_HPP_
#define ACCELERATIONCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../Vector2f/Vector2f.hpp"
#include "math.h"

namespace Engine {
    namespace Physic {
        namespace Components {
            struct MovementData {
                    Vector2f acceleration;
                    Vector2f velocity;
            };

            class MovementComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    MovementComponent(MovementData &data);
                    ~MovementComponent();
                    void     execute() override;
                    void     updateVelocity(float dt);
                    void     setAcceleration(Vector2f &acceleration);
                    void     setVelocity(Vector2f &velocity);
                    Vector2f getAcceleration() const;
                    Vector2f getVelocity() const;
                    void     normalize();

                protected:
                private:
                    MovementData &_data;
            };
        };  // namespace Components
    };      // namespace Physic
}  // namespace Engine

#endif /* !ACCELERATIONCOMPONENT_HPP_ */