/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MobTypeComponent
*/

#ifndef MOBTYPECOMPONENT_HPP_
#define MOBTYPECOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class MobTypeComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    MobTypeComponent(int data);
                    ~MobTypeComponent();
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

#endif /* !MOBTYPECOMPONENT_HPP_ */
