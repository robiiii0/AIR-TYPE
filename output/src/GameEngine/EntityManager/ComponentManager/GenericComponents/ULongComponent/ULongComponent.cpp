/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ULongComponent
*/

#include "ULongComponent.hpp"

template<typename T>
Engine::Entity::Component::GenericComponents::ULongComponent<T>::ULongComponent(
    unsigned long data) {
    if (value.type() == typeid(unsigned long)) {
        _component_name = "ULongComponent";
        _value = std::any_cast<unsigned long>(value); //TODO: fix this
    } else
        throw std::runtime_error("ULongComponent value is not unsigned long");
}

template<typename T>
Engine::Entity::Component::GenericComponents::ULongComponent<
    T>::~ULongComponent() {}

template<typename T>
void Engine::Entity::Component::GenericComponents::ULongComponent<
    T>::execute() {
    std::cout << "Executing ULongComponent" << std::endl;
}

template<typename T>
std::string Engine::Entity::Component::GenericComponents::ULongComponent<
    T>::getName() const {
    return (this->_component_name);
}
