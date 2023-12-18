/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include "../Entity/Entity.hpp"
#include "IComponent/IComponent.hpp"

const std::uint32_t __max_entities = 100;

namespace Engine {
    namespace Entity {
        namespace Component {
            class ComponentManager {
                public:
                    ComponentManager();
                    ~ComponentManager();

                    std::uint32_t addComponent(Entity&     entity,
                                               IComponent& component);
                    template<typename T>
                    bool removeComponent(Entity& entity, T component);

                    bool removeAllComponents(Entity& entity);

                    IComponent& getComponent(Entity&       entity,
                                             std::uint32_t component_id);
                    template<typename T>
                    bool hasComponent(Entity& entity, T component);

                    std::vector<Engine::Entity::Component::IComponent*>
                        getAllComponents(Entity& entity);

                protected:
                private:
                    std::array<std::uint32_t, __max_entities> _component_ids;
                    std::uint32_t                             _current_id;
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !COMPONENTMANAGER_HPP_ */
