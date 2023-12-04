/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** MobManager
*/

#ifndef MOBMANAGER_HPP_
#define MOBMANAGER_HPP_

#include "../EntityManager/EntityManager.hpp"

namespace Engine {
    namespace MobModule {
        class MobManager {
            public:
                MobManager();
                ~MobManager();

                std::uint32_t addComponent(
                    Engine::Entity::Entity                &entity,
                    Engine::Entity::Component::IComponent &component);
                bool removeComponent(Engine::Entity::Entity &entity,
                                     std::string             component_name);
                bool removeAllComponents(Engine::Entity::Entity &entity);
                Engine::Entity::Component::IComponent &getComponent(
                    Engine::Entity::Entity &entity, std::string component_name);
                bool hasComponent(Engine::Entity::Entity &entity,
                                  std::string             component_name);

            protected:
            private:
        };
    }  // namespace MobModule
}  // namespace Engine

#endif /* !MOBMANAGER_HPP_ */
