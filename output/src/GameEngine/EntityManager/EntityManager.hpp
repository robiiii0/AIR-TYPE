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
        const std::uint32_t __max_entities = 10000;
        const std::uint8_t  __max_components = 255;

        class EntityManager {
            public:
                EntityManager();
                std::uint32_t createEntity();

                Entity& getEntity(std::uint32_t id) {
                    for (std::uint32_t i = 0; i < _entities.size(); i++) {
                        if (_entities[i]._id == id) {
                            return _entities[i];
                        }
                    }
                    throw std::runtime_error("Entity not found");
                }

                void destroyEntity(const std::uint32_t& entity);
                template<typename T>
                void addComponent(Entity&                entity,
                                  T componentType);
                template<typename T>
                void removeComponent(Entity&     entity,
                                     T component);
                template<typename T>
                bool hasComponent(Entity& entity, T component) {
                    return _componentManager.hasComponent(entity,
                                                          component);
                }
                void getAllComponents(Entity& entity) {
                    _componentManager.getAllComponents(entity);
                }

                // template<typename T>
                // T& getComponentValue(Entity&     entity,
                //                      std::string component_name);

            private:
                std::queue<std::uint32_t>   _available_entities;
                uint32_t                    _living_entity_count;
                std::vector<Entity>         _entities;
                Component::ComponentManager _componentManager;
        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITYMANAGER_HPP_ */


/*
** EPITECH PROJECT, 2023
** r-type
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "IComponent.hpp"

#include <concepts>
#include <iostream>
#include <list>
#include <memory>

namespace ecs
{
    template <typename T>
    concept IsIComponent = std::derived_from<T, IComponent>;

    class Entity {
        public:
            Entity(unsigned int id);
            ~Entity() = default;

            const unsigned int Id;

            /**
         * @brief Add a component to the entity
             */
            template <IsIComponent C>
            void AddComponent(std::shared_ptr<C> component)
            {
                this->components.push_back(component);
            }

            /**
        * @brief Remove a component to the entity
             */
            template <IsIComponent C>
            void RemoveComponent(std::shared_ptr<C> component)
            {
                for (auto it = this->components.begin();
                     it != this->components.end();) {
                    if ((*it)->getTypeId() == typeid(C)) {
                        this->components.erase(it);
                        return;
                    } else
                        ++it;
                }
            }

            /**
         * @brief Return true if the entity have the specified component, else return false
             */
            template <IsIComponent C>
            bool HasComponent()
            {
                for (auto& component : this->components)
                    if (component->getTypeId() == typeid(C))
                        return (true);
                return (false);
            }

            /**
         * @brief End of the recursive method HasComponent
             */
            template <IsIComponent C>
            bool HasComponents()
            {
                return (this->HasComponent<C>());
            }

            /**
         * @brief Return true if the entity have the specified components, else return false
             */
            template <IsIComponent C1, IsIComponent C2, class... Other>
            bool HasComponents()
            {
                if (this->HasComponent<C1>())
                    return (this->HasComponents<C2, Other...>());
                return (false);
            }

            /**
         * @brief Return the component of the entity if it exists
             */
            template <IsIComponent C>
            std::shared_ptr<C> GetComponent()
            {
                if (!this->HasComponent<C>())
                    return (nullptr);
                for (auto& component : this->components)
                    if (component->getTypeId() == typeid(C))
                        return (std::static_pointer_cast<C>(component));
                return (nullptr);
            }

        protected:
        private:
            std::list<std::shared_ptr<IComponent>> components;
    };
}  // namespace ecs

#endif /* !ENTITY_HPP_ */