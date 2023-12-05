/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** VisionComponent
*/

#ifndef VISIONCOMPONENT_HPP_
#define VISIONCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            class VisionComponent :
                public Engine::Entity::Component::IComponent {
                public:
                    VisionComponent(std::uint32_t id,
                                    std::string component_name, std::any value);
                    ~VisionComponent();
                    void        execute() override;
                    std::any&   get() override;
                    std::string getName() const override;

                protected:
                private:
                    std::uint32_t _id;
                    std::string   _component_name;
                    int           _vision;
                    std::any      _ptr;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !VISIONCOMPONENT_HPP_ */
