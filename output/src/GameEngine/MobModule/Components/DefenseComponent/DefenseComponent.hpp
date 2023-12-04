/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** DefenseComponent
*/

#ifndef DEFENSECOMPONENT_HPP_
#define DEFENSECOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class DefenseComponent :
                public Engine::Entity::Component::IComponent {
                public:
                    DefenseComponent(std::uint32_t id,
                                     std::string   component_name,
                                     std::any      value);
                    ~DefenseComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    int           _defense;
                    std::any      _ptr;
            };
        };  // namespace Components
    };      // namespace MobModule
};          // namespace Engine
#endif      /* !DEFENSECOMPONENT_HPP_ */
