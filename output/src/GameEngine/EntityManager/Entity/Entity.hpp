/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "../ComponentManager/IComponent/IComponent.hpp"

namespace Engine {
    namespace Entity {
        struct Entity {
                std::uint32_t                        id;
                std::vector<Component::IComponent *> components;
        };
    }  // namespace Entity
}  // namespace Engine

#endif /* !ENTITY_HPP_ */
