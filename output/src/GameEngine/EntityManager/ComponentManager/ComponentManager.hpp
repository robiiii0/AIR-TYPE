/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ComponentManager
*/

#ifndef COMPONENTMANAGER_HPP_
#define COMPONENTMANAGER_HPP_

#include <array>

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

                    std::uint32_t addComponent(
                        std::shared_ptr<Entity>     entity,
                        std::shared_ptr<IComponent> component);
                    template<typename T>
                    bool removeComponent(std::shared_ptr<Entity> entity,
                                         T                       component);

                    bool removeAllComponents(std::shared_ptr<Entity> entity);

                    std::shared_ptr<IComponent> getComponent(
                        std::shared_ptr<Entity> entity,
                        std::uint32_t           component_id);
                    template<typename T>
                    bool hasComponent(std::shared_ptr<Entity> entity,
                                      T                       component);

                    std::vector<
                        std::shared_ptr<Engine::Entity::Component::IComponent>>
                        getAllComponents(std::shared_ptr<Entity> entity);

                protected:
                private:
                    std::array<std::uint32_t, __max_entities> _component_ids;
                    std::uint32_t                             _current_id;
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !COMPONENTMANAGER_HPP_ */
