/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** BoundingBoxComponent
*/

#include "BoundingBoxComponent.hpp"

template <typename T>
Engine::Physic::Components::BoundingBoxComponent<T>::BoundingBoxComponent(
    Data data) {
    if (data.type() == typeid(Data)) {
        _component_name = "BoundingBoxComponent";
        this->data = data;
    }
}

template <typename T>
Engine::Physic::Components::BoundingBoxComponent<T>::~BoundingBoxComponent() {}

template <typename T>
void Engine::Physic::Components::BoundingBoxComponent<T>::execute() {}

template <typename T>
std::string Engine::Physic::Components::BoundingBoxComponent<T>::getName() const {
    return (_component_name);
}

template <typename T>
void Engine::Physic::Components::BoundingBoxComponent<T>::setBoundingBox(
    Data data) {
        this->data = data;
}


