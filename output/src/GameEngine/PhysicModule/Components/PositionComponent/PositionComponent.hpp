/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** PositionComponent
*/

#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include <utility>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            class PositionComponent : public Engine::Entity::Component::AComponent{
                public:
                    PositionComponent(std::any value);
                    ~PositionComponent();

                    void execute() override;
                    std::any& get() override;
                    std::string getName() const override;

                    void setPos(std::pair<float, float> pos);
                protected:
                private:
                    std::pair<float, float> _pos;
                    std::string _component_name;
                    std::any _value;
            };
        };
    };
};


#endif /* !POSITIONCOMPONENT_HPP_ */
 