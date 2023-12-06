/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** StateComponent
*/

#ifndef STATECOMPONENT_HPP_
#define STATECOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class StateComponent :
                public Engine::Entity::Component::IComponent {
                public:
                    StateComponent(std::uint32_t id, std::string component_name,
                                   std::any value);
                    ~StateComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    bool          _state;
                    std::any      _ptr;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !STATECOMPONENT_HPP_ */
