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
                    std::uint32_t addComponent(Entity     &entity,
                                               IComponent &component);

                    bool removeComponent(Entity       &entity,
                                         std::uint32_t component_id);
                    bool removeAllComponents(Entity &entity);
                    IComponent getComponent(Entity &entity, std::uint32_t component_id);
                    bool hasComponent(Entity &entity, std::string component_name);

                protected:
                private:
                    std::array<std::uint32_t, __max_entities> _component_ids;
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !COMPONENTMANAGER_HPP_ */
