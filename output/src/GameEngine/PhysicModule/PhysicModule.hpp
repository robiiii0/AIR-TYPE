/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** PhysicModule
*/

#ifndef PHYSICMODULE_HPP_
#define PHYSICMODULE_HPP_

#include "../EntityManager/Entity/Entity.hpp"
#include "../EntityManager/EntityManager.hpp"
#include "Components/BoundingBoxComponent/BoundingBoxComponent.hpp"
#include "Components/MovementComponent/MovementComponent.hpp"
#include "Components/TransformComponent/TransformComponent.hpp"

namespace Engine {
    namespace Physic {
        class PhysicModule {
            public:
                PhysicModule();
                ~PhysicModule();
                void update(Engine::Entity::EntityManager &entityManager,
                            std::vector<uint32_t> id_list, float dt);

            protected:
            private:
        };
    };  // namespace Physic
};      // namespace Engine

#endif /* !PHYSICMODULE_HPP_ */
