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
            class MassComponent : public Engine::Entity::Component::AComponent {
                public:
                    MassComponent(std::any value);
                    ~MassComponent();

                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                    void setMass(float mass);

                protected:
                private:
                    float       _mass;
                    std::string _component_name;
                    std::any    _value;
            };
        };  // namespace Components
    };      // namespace Physic
}  // namespace Engine

#endif /* !MASSCOMPONENT_HPP_ */
