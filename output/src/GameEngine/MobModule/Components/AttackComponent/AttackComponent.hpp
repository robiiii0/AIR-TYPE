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

            class AttackComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    AttackComponent(int data);
                    ~AttackComponent();
                    void execute() override;
                    int &getValue();
                    void setValue(int value);


                protected:
                private:
                    int _value;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !ATTACKCOMPONENT_HPP_ */
