/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** HealthComponent
*/

#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {

            struct HealthComponentData {
                    int health;
                    int maxHealth;
            };

            template<typename T>
            class HealthComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    HealthComponent(HealthComponentData data);
                    ~HealthComponent();
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

#endif /* !HEALTHCOMPONENT_HPP_ */
