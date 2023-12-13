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
            template<typename T>
            class IAComponent : public Engine::Entity::Component::AComponent {
                public:
                    IAComponent(int data);
                    ~IAComponent();
                    void        execute() override;
                    std::string getName() const override;

                protected:
                private:
                    std::string _component_name;
                    T           _data;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !IACOMPONENT_HPP_ */
