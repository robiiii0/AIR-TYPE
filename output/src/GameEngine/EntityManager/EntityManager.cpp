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
 * This constructor initializes the availableEntities stack with entity IDs from
 * 0 to MAX_ENTITIES-1.
 */

Engine::Entity::EntityManager::EntityManager() {
    _componentManager = Component::ComponentManager();
    for (std::uint32_t i = 0; i < __max_entities; i++)
        _available_entities.push(i);
}

/**
 * @brief Creates an entity by popping an entity ID from the available entities
 * pool and incrementing the living entity count.
 *
 * @return The ID of the created entity.
 */

std::uint32_t Engine::Entity::EntityManager::createEntity() {
    std::cout << "Available entities: " << std::endl;
//    std::uint32_t id = _available_entities.front();
    std::uint32_t id = 0;
    _available_entities.pop();
    _living_entity_count++;
    std::cout << "Created entity " << id << std::endl;
    Entity entity(id);
    _entities.push_back(entity);
    return id;
}

/**
 * @brief Destroys an entity by resetting its signature, adding it back to the
 * available entities pool, and decrementing the living entity count.
 *
 * @param entity The ID of the entity to destroy.
 */

void Engine::Entity::EntityManager::destroyEntity(
    const std::uint32_t& entity_id) {
    // signatures[entity] = 0;
    _available_entities.push(entity_id);
    _living_entity_count--;
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]._id == entity_id) {
            _entities.erase(_entities.begin() + i);
            break;
        }
    }
    std::cout << "Destroyed entity " << entity_id << std::endl;
}

/**
 * Adds a component to the specified entity.
 *
 * @param entity The entity to add the component to.
 * @param component The component to add.
 */

void Engine::Entity::EntityManager::addComponent(Entity& entity, Engine::Entity::Component::IComponent& component) {
    _componentManager.addComponent(entity, component);
}

/**
 * Removes a component from an entity.
 * If the component_name is "all", removes all components from the entity.
 * If the component_name is valid and exists in the entity, removes the
 * specified component. If the component_name is invalid or does not exist in
 * the entity, displays an error message.
 *
 * @param entity The entity from which to remove the component.
 * @param component_name The name of the component to remove.
 */

template<typename T>
void Engine::Entity::EntityManager::removeComponent(Entity& entity,
                                                    T       component) {
    _componentManager.removeComponent(entity, component);
}

/**
 * Retrieves the value of a component from the specified entity.
 *
 * @tparam T The type of the component value to retrieve.
 * @param entity The entity from which to retrieve the component value.
 * @param component_name The name of the component.
 * @return The value of the component.
 */
//
// T& Engine::Entity::EntityManager::getComponentValue(
//     Entity& entity, std::string component_name) {
//     return entity.getComponentValue(component_name);
// }
