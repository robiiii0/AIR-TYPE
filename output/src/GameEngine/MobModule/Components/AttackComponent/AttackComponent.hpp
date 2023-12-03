/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#ifndef ATTACKCOMPONENT_HPP_
#define ATTACKCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class AttackComponent :
                public Engine::Entity::Component::IComponent { // a supprimer si on ajoute weaponManager
                public:
                    AttackComponent(std::uint32_t id,
                                    std::string component_name, std::any value);
                    ~AttackComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    int           _damage;
                    std::any      _ptr;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !ATTACKCOMPONENT_HPP_ */
