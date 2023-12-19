/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** IAComponent
*/

#ifndef IACOMPONENT_HPP_
#define IACOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class IAComponent : public Engine::Entity::Component::AComponent {
                public:
                    IAComponent(int data);
                    ~IAComponent();
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

#endif /* !IACOMPONENT_HPP_ */
