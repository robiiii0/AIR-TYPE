/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ULongComponent
*/

#include "ULongComponent.hpp"

Engine::Entity::Component::GenericComponents::ULongComponent::~ULongComponent()
{}

void Engine::Entity::Component::GenericComponents::ULongComponent::execute()
{
    std::cout << "Executing ULongComponent" << std::endl;
}

std::any& Engine::Entity::Component::GenericComponents::ULongComponent::get() {
    return (this->_value);
}

// std::uint32_t
//     Engine::Entity::Component::GenericComponents::ULongComponent::getId()
//         const {
//     return (this->_id);
// }

// void Engine::Entity::Component::GenericComponents::ULongComponent::setId(
//     std::uint32_t id) {
//     this->_id = id;
// }

std::string
Engine::Entity::Component::GenericComponents::ULongComponent::getName() const
{
    return (this->_component_name);
}
