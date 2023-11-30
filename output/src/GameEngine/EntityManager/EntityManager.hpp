/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** EntityManager
*/

// TODO add namespace

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <array>
#include <bitset>
#include <cstdint>
#include <iostream>
#include <queue>

#include "Entity/Entity.hpp"

namespace Engine {
    namespace Entity {
        const std::uint32_t __max_entities = 100;
        const std::uint8_t  __max_components = 255;

        class EntityManager {
            public:
                EntityManager();
                std::uint32_t createEntity();

                void destroyEntity(const std::uint32_t &entity);

                // void setSignature(std::uint32_t               entity,
                //                   std::bitset<MAX_COMPONENTS> signature);

                // std::bitset<MAX_COMPONENTS> getSignature(std::uint32_t
                // entity);

            private:
                std::queue<std::uint32_t> _available_entities;

                uint32_t _living_entity_count;

                std::vector<Entity> _entities;

                // the signature is a unique identifier for each entity to know
                // which components it has attached to it. ReadMe for more info
                // std::bitset<MAX_COMPONENTS> signatures;
        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITYMANAGER_HPP_ */
