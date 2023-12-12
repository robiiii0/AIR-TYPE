/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "../ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace Entity {
        class Entity {
            public:
                Entity(std::uint32_t id) : id(id) {}

                ~Entity() = default;

                /**
                 * Retrieves the value of a component with the specified name.
                 * 
                 * @tparam T The type of the component value to retrieve.
                 * @param component_name The name of the component.
                 * @return A pointer to the component value if found, nullptr otherwise.
                 * @throws std::runtime_error if the component is not found.
                 */
                template<typename T>
                T* getComponentValue(std::string component_name) {
                    for (auto& component : components) {
                        if (component->getName() == component_name) {
                            if (auto derived =
                                    std::dynamic_pointer_cast<Component<T>>(
                                        component))
                                return derived->_data();
                        }
                    }
                    throw std::runtime_error("Component not found");
                }

                std::uint32_t                       id;
                std::vector<Component::IComponent*> components;
        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITY_HPP_ */
