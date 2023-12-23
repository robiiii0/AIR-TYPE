/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotRemoveComponent
*/

#ifndef COULDNOTREMOVECOMPONENT_HPP_
#define COULDNOTREMOVECOMPONENT_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class CouldNotRemoveComponent : public std::exception {
            public:
                CouldNotRemoveComponent();
                ~CouldNotRemoveComponent();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !COULDNOTREMOVECOMPONENT_HPP_ */
