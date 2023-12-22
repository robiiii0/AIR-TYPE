/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** PhysicModule
*/

#include "PhysicModule.hpp"

Engine::Physic::PhysicModule::PhysicModule() {
    // TODO: World settings
}

Engine::Physic::PhysicModule::~PhysicModule() {}

void Engine::Physic::PhysicModule::update(
    Engine::Entity::EntityManager &entityManager,
    std::vector<uint32_t>          id_list, float dt) {
    for (auto &id : id_list) {
        auto components = entityManager.getAllComponents(id);
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::Physic::Components::BoundingBoxComponent)) {
                auto hitbox = std::dynamic_pointer_cast<
                    Engine::Physic::Components::BoundingBoxComponent>(
                    component);
                std::cout << "Hitbox: " << hitbox->getBoundingBox().pos.x
                          << hitbox->getBoundingBox().pos.y << std::endl;
                for (auto &id2 : id_list) {
                    if (id2 != id) {
                        auto components2 = entityManager.getAllComponents(id2);
                        for (auto &component2 : components2) {
                            if (typeid(*component2) ==
                                typeid(Engine::Physic::Components::
                                           BoundingBoxComponent)) {
                                auto hitbox2 = std::dynamic_pointer_cast<
                                    Engine::Physic::Components::
                                        BoundingBoxComponent>(component2);
                                std::cout << "Hitbox2: "
                                          << hitbox2->getBoundingBox().pos.x
                                          << hitbox2->getBoundingBox().pos.y
                                          << std::endl;
                                if (hitbox->getBoundingBox().pos.x ==
                                        hitbox2->getBoundingBox().pos.x &&
                                    hitbox->getBoundingBox().pos.y ==
                                        hitbox2->getBoundingBox().pos.y) {
                                    std::cout << "COLLISION" << std::endl;
                                }
                            }
                        }
                    }
                }
                if (typeid(*component) ==
                    typeid(Engine::Physic::Components::MovementComponent)) {
                    auto movement = std::dynamic_pointer_cast<
                        Engine::Physic::Components::MovementComponent>(
                        component);
                    auto transform = std::dynamic_pointer_cast<
                        Engine::Physic::Components::TransformComponent>(
                        component);
                    movement->updateVelocity(dt);
                    transform->setPos(
                        (transform->getPos() + movement->getVelocity())); // TODO: Add the dt (velocity * dt)
                }
            }
        }
    }
}

bool Engine::Physic::PhysicModule::isColliding(Entity::Entity &entity1,
                                               Entity::Entity &entity2) {
    return false;
}
