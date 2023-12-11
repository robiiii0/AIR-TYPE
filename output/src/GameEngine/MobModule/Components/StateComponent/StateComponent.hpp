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
            template <typename T>
            class StateComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    StateComponent(bool data);
                    ~StateComponent();
                    void        execute() override;
                    std::string getName() const override;

                protected:
                private:
                    std::string   _component_name;
                    T _data;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !STATECOMPONENT_HPP_ */
