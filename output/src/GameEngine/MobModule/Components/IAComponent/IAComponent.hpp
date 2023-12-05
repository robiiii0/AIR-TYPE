/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** IAComponent
*/

#ifndef IACOMPONENT_HPP_
#define IACOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class IAComponent : public Engine::Entity::Component::IComponent {
                public:
                    IAComponent(std::uint32_t id, std::string component_name,
                                std::any value);
                    ~IAComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    int           _ia;
                    std::any      _ptr;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !IACOMPONENT_HPP_ */
