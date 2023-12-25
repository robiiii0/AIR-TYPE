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
    Engine::Entity::EntityManager &entityManager, std::vector<uint32_t> id_list,
    float dt) {
        std::cout << "UPDATE" << std::endl;
    for (auto &id : id_list) {
        auto components = entityManager.getAllComponents(id);
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::Physic::Components::BoundingBoxComponent)) {
                auto hitbox = std::dynamic_pointer_cast<
                    Engine::Physic::Components::BoundingBoxComponent>(
                    component);
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
                                if (*hitbox == *hitbox2) {
                                    std::cout << "COLLISION" << std::endl;
                                }
                            }
                        }
                    }
                }
            }
            std::cout << typeid(*component).name() << std::endl;
                if (typeid(*component) ==
                    typeid(Engine::Physic::Components::MovementComponent)) {
                    auto movement = std::dynamic_pointer_cast<
                        Engine::Physic::Components::MovementComponent>(
                        component);
                    auto transform = std::dynamic_pointer_cast<
                        Engine::Physic::Components::TransformComponent>(
                        component);
                    std::cout << movement << std::endl;
                    movement->updateVelocity(dt);
                    transform->setPos(500.0, 10.0);
                    // std::cout << transform->getPos().x << std::endl;
                }
        }
    }
}

bool Engine::Physic::PhysicModule::isColliding(Entity::Entity &entity1,
                                               Entity::Entity &entity2) {
    return false;
}
