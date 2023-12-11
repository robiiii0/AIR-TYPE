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
            template<typename T>
            class PositionComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    PositionComponent(T data, std::pair<float, float>);
                    ~PositionComponent();
                    void        execute() override;
                    std::string getName() const override;
                    void        setPos(std::pair<float, float> pos);

                protected:
                private:
                    std::pair<float, float> _pos;
                    std::string             _component_name;
                    T                       data;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine

#endif /* !POSITIONCOMPONENT_HPP_ */
