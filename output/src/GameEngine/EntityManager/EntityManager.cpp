/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** EntityManager
*/

// TODO faire des throw pour les erreurs (example : si on veut créer une entité et qu'il ny a plus de place)

#include "EntityManager.hpp"

/**
 * @brief Constructs an instance of the EntityManager class.
 *
 * This constructor initializes the availableEntities stack with entity IDs from
 * 0 to MAX_ENTITIES-1.
 */
Engine::Entity::EntityManager::EntityManager() {
    for (std::uint32_t i = 0; i < __max_entities; i++) _available_entities.push(i);
}

/**
 * @brief Creates an entity by popping an entity ID from the available entities
 * pool and incrementing the living entity count.
 *
 * @return The ID of the created entity.
 */
std::uint32_t Engine::Entity::EntityManager::createEntity() {
    std::uint32_t id = _available_entities.front();
    _available_entities.pop();
    _living_entity_count++;
    std::cout << "Created entity " << id << std::endl;
    Entity entity;
    entity.id = id;
    _entities.push_back(entity);
    return id;
}

/**
 * @brief Destroys an entity by resetting its signature, adding it back to the
 * available entities pool, and decrementing the living entity count.
 *
 * @param entity The ID of the entity to destroy.
 */
void Engine::Entity::EntityManager::destroyEntity(const std::uint32_t &entity_id) {
    // signatures[entity] = 0;
    _available_entities.push(entity_id);
    _living_entity_count--;
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i].id == entity_id) {
            _entities.erase(_entities.begin() + i);
            break;
        }
    }
    std::cout << "Destroyed entity " << entity_id << std::endl;
}

/**
 * @brief Sets the signature of an entity.
 *
 * @param entity The entity ID.
 * @param signature The signature to set for the entity.
 */
// void EntityManager::setSignature(std::uint32_t               entity,
//                                  std::bitset<MAX_COMPONENTS> signature) {
//     signatures[entity] = signature;
// }

/**
 * @brief Retrieves the signature of an entity.
 *
 * @param entity The entity for which to retrieve the signature.
 * @return The signature of the entity.
 */
// std::bitset<MAX_COMPONENTS> EntityManager::getSignature(std::uint32_t entity) {
//     return signatures[entity];
// }
