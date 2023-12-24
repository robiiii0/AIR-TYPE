/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#ifndef ACCELERATIONCOMPONENT_HPP_
#define ACCELERATIONCOMPONENT_HPP_

#include <ostream>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../Vector2f/Vector2f.hpp"
#include "math.h"

namespace Engine {
    namespace Physic {
        namespace Components {
            struct MovementData {
                    Vector2f acceleration;
                    Vector2f velocity;
                    float    maxVelocity;
            };

            class MovementComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    MovementComponent(MovementData &data);
                    //   MovementComponent(Vector2f acceleration, Vector2f
                    //   velocity,
                    //                     float maxVelocity);
                    ~MovementComponent();
                    void     execute() override;
                    void     updateVelocity(float dt);
                    void     setAcceleration(Vector2f &acceleration);
                    void     setVelocity(Vector2f &velocity);
                    void     setMaxVelocity(float maxVelocity);
                    Vector2f getAcceleration() const;
                    Vector2f getVelocity() const;
                    float    getMaxVelocity() const;
                    void     normalize();

                    friend std::ostream &operator<<(std::ostream      &os,
                                                    MovementComponent &mc) {
                        os << "Acceleration: " << mc._acceleration.x << ", "
                           << mc._acceleration.y << "\n"
                           << "Velocity: " << mc._velocity.x << ", "
                           << mc._velocity.y << "\n"
                           << "Max Velocity: " << mc._maxVelocity << "\n";
                        return os;
                    }

                protected:
                private:
                    MovementData &_data;
                    float         _maxVelocity;
                    Vector2f      _acceleration;
                    Vector2f      _velocity;
            };
        };  // namespace Components
    };      // namespace Physic
}  // namespace Engine

#endif /* !ACCELERATIONCOMPONENT_HPP_ */
