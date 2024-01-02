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
        _living_entity_count = 0;
    //    _entities.clear();
}

/**
 * @brief Creates an entity by popping an entity ID from the available entities
 * pool and incrementing the living entity count.
 *
 * @return The ID of the created entity.
 */
std::uint32_t Engine::Entity::EntityManager::getNbEntites() {
    return _entities.size();
}

std::uint32_t Engine::Entity::EntityManager::createEntity() {
    if (_living_entity_count >= __max_entities) {
        throw Engine::EntityManager::CouldNotCreateEntity();
        return -1;
    }
    std::uint32_t id = _entities.size();
    _available_entities.pop();
    _living_entity_count++;
    Entity entity(id);
    _entities.push_back(std::make_shared<Entity>(entity));
    return id;
}

std::shared_ptr<Engine::Entity::Entity>
    Engine::Entity::EntityManager::getEntity(const std::uint32_t& id) {
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]->_id == id) {
            return _entities[i];
        }
    }
    throw Engine::EntityManager::CouldNotFindEntity();
    return nullptr;
}

/**
 * @brief Destroys an entity by resetting its signature, adding it back to the
 * available entities pool, and decrementing the living entity count.
 *
 * @param entity The ID of the entity to destroy.
 */
std::vector<std::uint32_t> Engine::Entity::EntityManager::destroyEntity(
    const std::uint32_t& entity_id) {
    // signatures[entity] = 0;
    _available_entities.push(entity_id);
    _living_entity_count--;

    std::vector<std::uint32_t> newList;

    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        std::cout << "existing entity: " << _entities[i]->_id << std::endl;
        newList.push_back(_entities[i]->_id);
    }

    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]->_id == entity_id) {
            _entities.erase(_entities.begin() + i);
            newList.erase(newList.begin() + i);
            return newList;
            ;
        }
    }
}

/**
 * Adds a component to the specified entity.
 *
 * @param entity The entity to add the component to.
 * @param component The component to add.
 */

void Engine::Entity::EntityManager::addComponent(
    const std::uint32_t&                                   entity_id,
    std::shared_ptr<Engine::Entity::Component::IComponent> component) {
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]->_id == entity_id) {
            for (std::uint32_t j = 0; j < _entities[i]->_components.size();
                 j++) {
                if (_entities[i]->_components[j] == component) {
                    throw Engine::EntityManager::ComponentAlreadyExists();
                }
            }
            _componentManager.addComponent(_entities[i], component);
            return;
        }
    }
    throw Engine::EntityManager::CouldNotFindEntity();
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
void Engine::Entity::EntityManager::removeComponent(const std::uint32_t& id,
                                                    T component) {
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        // TODO: si le component n'existe pas, throw une exception
        if (_entities[i]->_id == id) {
            for (std::uint32_t j = 0; j < _entities[i]->_components.size();
                 j++) {
                if (_entities[i]->_components[j] == component) {
                    _componentManager.removeComponent(_entities[i], component);
                    return;
                }
            }
            throw Engine::EntityManager::CouldNotFindComponent();
        }
    }
    throw Engine::EntityManager::CouldNotFindEntity();
}

template<typename T>
bool Engine::Entity::EntityManager::hasComponent(const std::uint32_t& entity_id,
                                                 T component) {
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]->_id == entity_id) {
            return _componentManager.hasComponent(_entities[i], component);
        }
    }
}

std::vector<std::shared_ptr<Engine::Entity::Component::IComponent>>
    Engine::Entity::EntityManager::getAllComponents(const std::uint32_t& id) {
    for (std::uint32_t i = 0; i < _entities.size(); i++) {
        if (_entities[i]->_id == id) {
            if (_entities[i]->_components.size() == 0) {
                throw Engine::EntityManager::NoComponent();
            }
            return _componentManager.getAllComponents(_entities[i]);
        }
    }
    throw Engine::EntityManager::CouldNotFindEntity();
}
