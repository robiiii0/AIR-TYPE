/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MassComponent
*/

#ifndef MASSCOMPONENT_HPP_
#define MASSCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            template<typename T>
            class MassComponent : public Engine::Entity::Component::AComponent {
                public:
                    MassComponent(T data);
                    ~MassComponent();
                    void        execute() override;
                    std::string getName() const override;
                    void        setMass(float mass);

                protected:
                private:
                    float       _mass;
                    std::string _component_name;
                    T           data;
            };
        };  // namespace Components
    };      // namespace Physic
}  // namespace Engine

#endif /* !MASSCOMPONENT_HPP_ */
