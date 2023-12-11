/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AccelerationComponent
*/

#ifndef ACCELERATIONCOMPONENT_HPP_
#define ACCELERATIONCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            class AccelerationComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    AccelerationComponent(std::any value);
                    ~AccelerationComponent();

                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                    void setAcceleration(std::pair<float, float> acceleration);

                protected:
                private:
                    std::pair<float, float> _acceleration;
                    std::string             _component_name;
                    std::any                _value;
            };
        };  // namespace Components
    };      // namespace Physic
}  // namespace Engine

#endif /* !ACCELERATIONCOMPONENT_HPP_ */
