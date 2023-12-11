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
            template<typename T>
            class DefenseComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    DefenseComponent(int data);
                    ~DefenseComponent();
                    void        execute() override;
                    std::string getName() const override;

                protected:
                private:
                    std::string _component_name;
                    T           _data;
            };
        };  // namespace Components
    };      // namespace MobModule
};          // namespace Engine
#endif      /* !DEFENSECOMPONENT_HPP_ */
