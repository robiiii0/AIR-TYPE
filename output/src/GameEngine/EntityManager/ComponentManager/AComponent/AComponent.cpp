/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AComponent
*/

#include "AComponent.hpp"

template<typename T>
std::uint32_t Engine::Entity::Component::AComponent<T>::getId() const {
    return this->_id;
}

template<typename T>
void Engine::Entity::Component::AComponent<T>::setId(std::uint32_t id) {
    this->_id = id;
}
