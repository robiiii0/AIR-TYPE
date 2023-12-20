/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ComponentAlreadyExists
*/

#ifndef COMPONENTALREADYEXISTS_HPP_
#define COMPONENTALREADYEXISTS_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class ComponentAlreadyExists : public std::exception {
            public:
                ComponentAlreadyExists();
                ~ComponentAlreadyExists();

                const char *what() const noexcept override;
        };
    }  // namespace EntityManager
}  // namespace Engine

#endif /* !COMPONENTALREADYEXISTS_HPP_ */
