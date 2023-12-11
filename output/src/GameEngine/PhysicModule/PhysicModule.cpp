/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** PhysicModule
*/

#include "PhysicModule.hpp"

template<typename T>
Engine::Physic::PhysicModule<T>::PhysicModule() {
    // TODO: World settings
}

template<typename T>
Engine::Physic::PhysicModule<T>::~PhysicModule() {}

template<typename T>
void Engine::Physic::PhysicModule<T>::update() {}

template<typename T>
bool Engine::Physic::PhysicModule<T>::isColliding(Entity::Entity &entity1,
                                                  Entity::Entity &entity2) {
    T data1;
    T data2;
    data1 = entity1.getComponentValue("BoundingBoxComponent");
    data2 = entity2.getComponentValue("BoundingBoxComponent");
    if (data1._pos.first < data2._pos.first + data2._size.first &&
        data1._pos.first + data1._size.first > data2._pos.first &&
        data1._pos.second < data2._pos.second + data2._size.second &&
        data1._pos.second + data1._size.second > data2._pos.second) {
        std::cout << entity1.id << " colliding with " << entity2.id
                  << std::endl;
        return true;
    } else {
        return false;
    }
}
