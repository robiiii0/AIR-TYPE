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
            template <typename T>
            class MobTypeComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    MobTypeComponent(int data);
                    ~MobTypeComponent();
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

#endif /* !MOBTYPECOMPONENT_HPP_ */
