/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#ifndef ATTACKCOMPONENT_HPP_
#define ATTACKCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            template<typename T>
            class AttackComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    AttackComponent(int data);
                    ~AttackComponent();
                    void        execute() override;

                protected:
                private:
                    std::string _component_name;
                    T           _data;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !ATTACKCOMPONENT_HPP_ */
