/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** HealthComponent
*/

#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {

            struct HealthComponentData {
                    int health;
                    int maxHealth;
            };

            class HealthComponent :
                public Engine::Entity::Component::IComponent {
                public:
                    HealthComponent(std::uint32_t id,
                                    std::string component_name, std::any value);
                    ~HealthComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t       _id;
                    std::string         _component_name;
                    HealthComponentData _data;
                    std::any            _ptr;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !HEALTHCOMPONENT_HPP_ */
