/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <cstdint>

#include "../EntityManager.hpp"
#include "IComponent/IComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            class ComponentManager {
                public:
                    ComponentManager();
                    ~ComponentManager();
                    static bool addComponent(std::uint32_t entity,
                                             IComponent   *component);

                    // static bool      removeComponent(std::uint32_t entity,
                    //                                  Component component);
                    // static bool      RemoveAllComponents(std::uint32_t
                    // entity); static Component getComponent(std::uint32_t
                    // entity); static bool      hasComponent(std::uint32_t
                    // entity);

                protected:
                private:
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !COMPONENTMANAGER_HPP_ */
