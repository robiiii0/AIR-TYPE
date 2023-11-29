/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** EntityManager
*/

#include "EntityManager.hpp"

/**
 * @brief Constructs an instance of the EntityManager class.
 * 
 * This constructor initializes the availableEntities stack with entity IDs from 0 to MAX_ENTITIES-1.
 */
EntityManager::EntityManager()
{
    for (int i = 0; i < MAX_ENTITIES; i++)
        availableEntities.push(i);
}

/**
 * @brief Creates an entity by popping an entity ID from the available entities pool and incrementing the living entity count.
 * 
 * @return The ID of the created entity.
 */
std::uint32_t EntityManager::createEntity()
{
    std::uint32_t id = availableEntities.front();
    availableEntities.pop();
    livingEntityCount++;
    return id;
}

/**
 * @brief Destroys an entity by resetting its signature, adding it back to the available entities pool, and decrementing the living entity count.
 * 
 * @param entity The ID of the entity to destroy.
 */
void EntityManager::destroyEntity(std::uint32_t entity)
{
    signatures[entity] = 0;
    availableEntities.push(entity);
    livingEntityCount--;
}

/**
 * @brief Sets the signature of an entity.
 * 
 * @param entity The entity ID.
 * @param signature The signature to set for the entity.
 */
void EntityManager::setSignature(std::uint32_t entity, std::bitset<MAX_COMPONENTS> signature)
{
    signatures[entity] = signature;
}

/**
 * @brief Retrieves the signature of an entity.
 *
 * @param entity The entity for which to retrieve the signature.
 * @return The signature of the entity.
 */
std::bitset<MAX_COMPONENTS> EntityManager::getSignature(std::uint32_t entity)
{
    return signatures[entity];
}
