/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** NoComponent
*/

#ifndef NOCOMPONENT_HPP_
#define NOCOMPONENT_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class NoComponent : public std::exception {
            public:
                NoComponent();
                ~NoComponent();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !NOCOMPONENT_HPP_ */
