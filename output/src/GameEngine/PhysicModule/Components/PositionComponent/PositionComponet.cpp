/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** PositionComponet
*/

#include "PositionComponent.hpp"

template<typename T>
Engine::Physic::Components::PositionComponent<T>::PositionComponent(
    T data, std::pair<float, float> pos) {
    _component_name = "PositionComponent";
    _pos = std::any_cast<std::pair<float, float>>(pos);
    this->data = data;
}

template<typename T>
Engine::Physic::Components::PositionComponent<T>::~PositionComponent() {}

template<typename T>
void Engine::Physic::Components::PositionComponent<T>::execute() {}

template<typename T>
std::string Engine::Physic::Components::PositionComponent<T>::getName() const {
    return (_component_name);
}

template<typename T>
void Engine::Physic::Components::PositionComponent<T>::setPos(
    std::pair<float, float> pos) {
    _pos = pos;
}
