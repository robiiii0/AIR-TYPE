/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** VisionComponent
*/

#ifndef VISIONCOMPONENT_HPP_
#define VISIONCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class VisionComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    VisionComponent(int data);
                    ~VisionComponent();
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

#endif /* !VISIONCOMPONENT_HPP_ */
