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

            template <typename T>
            T* getComponentValue(std::string component_name) {
                for (auto& component : components) {
                    if (component->getName() == component_name) {
                        if (auto derived = std::dynamic_pointer_cast<Component<T>>(component))
                            return derived->_data();
                    }
                }
                throw std::runtime_error("Component not found");
            }

            std::uint32_t                        id;
            std::vector<Component::IComponent *> components;

        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITY_HPP_ */
