/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** DefenseComponent
*/

#ifndef DEFENSECOMPONENT_HPP_
#define DEFENSECOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class DefenseComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    DefenseComponent(int data);
                    ~DefenseComponent();
                    void        execute() override;
                    int &       getValue();
                    void        setValue(int value);

                protected:
                private:
                    int           _value;
            };
        };  // namespace Components
    };      // namespace MobModule
};          // namespace Engine
#endif      /* !DEFENSECOMPONENT_HPP_ */
