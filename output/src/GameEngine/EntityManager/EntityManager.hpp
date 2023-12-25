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
#include "exceptions/ComponentAlreadyExists/ComponentAlreadyExists.hpp"
#include "exceptions/CouldNotAddComponent/CouldNotAddComponent.hpp"
#include "exceptions/CouldNotAddEntity/CouldNotAddEntity.hpp"
#include "exceptions/CouldNotCreateEntity/CouldNotCreateEntity.hpp"
#include "exceptions/CouldNotFindComponent/CouldNotFindComponent.hpp"
#include "exceptions/CouldNotFindEntity/CouldNotFindEntity.hpp"
#include "exceptions/NoComponent/NoComponent.hpp"

namespace Engine {
    namespace Entity {
        const std::uint32_t __max_entities = 10000;
        const std::uint8_t  __max_components = 255;

        class EntityManager {
            public:
                EntityManager();
                std::uint32_t createEntity();

                std::shared_ptr<Entity> getEntity(const std::uint32_t& id);

                uint32_t getNbEntites();

                std::vector<std::uint32_t> destroyEntity(const std::uint32_t& entity_id);
                void addComponent(
                    const std::uint32_t&                   entity_id,
                    std::shared_ptr<Component::IComponent> componentType);
                template<typename T>
                void removeComponent(const std::uint32_t& entity_id,
                                     T                    component);

                template<typename T>
                bool hasComponent(const std::uint32_t& entity_id, T component);

                std::vector<std::shared_ptr<Component::IComponent>>
                    getAllComponents(const std::uint32_t& entity_id);

            private:
                std::queue<std::uint32_t>            _available_entities;
                uint32_t                             _living_entity_count;
                std::vector<std::shared_ptr<Entity>> _entities;
                Component::ComponentManager          _componentManager;
        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITYMANAGER_HPP_ */
