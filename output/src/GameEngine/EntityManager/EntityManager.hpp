/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <array>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <queue>

#include "ComponentManager/ComponentManager.hpp"
#include "Entity/Entity.hpp"

namespace Engine {
    namespace Entity {
        const std::uint32_t __max_entities = 100;
        const std::uint8_t  __max_components = 255;

        class EntityManager {
            public:
                EntityManager();
                std::uint32_t createEntity();

                Entity& getEntity(std::uint32_t id) {
                    for (std::uint32_t i = 0; i < _entities.size(); i++) {
                        if (_entities[i].id == id) {
                            return _entities[i];
                        }
                    }
                    throw std::runtime_error("Entity not found");
                }

                void destroyEntity(const std::uint32_t& entity);

                void addComponent(Entity&                entity,
                                  Component::IComponent& component);
                void removeComponent(Entity&     entity,
                                     std::string component_name);

                bool hasComponent(Entity& entity, std::string component_name) {
                    return _componentManager.hasComponent(entity,
                                                          component_name);
                }

                void getAllComponents(Entity& entity) {
                    _componentManager.getAllComponents(entity);
                }

                std::any& getComponentValue(Entity&     entity,
                                            std::string component_name) {
                    return _componentManager.getComponentValue(entity,
                                                               component_name);
                }

            private:
                std::queue<std::uint32_t> _available_entities;

                uint32_t _living_entity_count;

                std::vector<Entity>         _entities;
                Component::ComponentManager _componentManager;
        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITYMANAGER_HPP_ */
