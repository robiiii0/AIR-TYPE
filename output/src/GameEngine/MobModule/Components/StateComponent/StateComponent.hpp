/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** StateComponent
*/

#ifndef STATECOMPONENT_HPP_
#define STATECOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class StateComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    StateComponent(bool data);
                    ~StateComponent();
                    void        execute() override;
                     bool &       getValue();
                     void        setValue(bool value);

                protected:
                private:
                    bool _value;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !STATECOMPONENT_HPP_ */
