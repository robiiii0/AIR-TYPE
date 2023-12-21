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

namespace Engine {
    namespace Physic {
        class PhysicModule {
            public:
                PhysicModule();
                ~PhysicModule();
                void update();
                bool isColliding(Entity::Entity &entity1,
                                 Entity::Entity &entity2);

            protected:
            private:
        };
    };  // namespace Physic
};      // namespace Engine

#endif /* !PHYSICMODULE_HPP_ */
