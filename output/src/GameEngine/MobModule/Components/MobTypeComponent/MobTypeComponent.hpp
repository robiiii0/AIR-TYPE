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
                    MobTypeComponent(std::uint32_t id,
                                     std::string   component_name,
                                     std::any      value);
                    ~MobTypeComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    int           _type;
                    std::any      _ptr;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !MOBTYPECOMPONENT_HPP_ */
