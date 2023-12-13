/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** VelocityComponent
*/

/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** VelocityComponent
*/

#ifndef VELOCITYCOMPONENT_HPP_
#define VELOCITYCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            template<typename T>
            class VelocityComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    VelocityComponent(T data);
                    ~VelocityComponent();
                    void        execute() override;
                    std::string getName() const override;
                    void        setVelocity(std::pair<float, float> velocity);

                protected:
                private:
                    std::pair<float, float> _velocity;
                    std::string             _component_name;
                    T                       data;
            };
        };  // namespace Components
    };      // namespace Physic
}  // namespace Engine

#endif /* !VELOCITYCOMPONENT_HPP_ */
