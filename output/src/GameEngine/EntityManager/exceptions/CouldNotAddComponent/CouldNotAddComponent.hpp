/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotAddComponent
*/

#ifndef COULDNOTADDCOMPONENT_HPP_
#define COULDNOTADDCOMPONENT_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class CouldNotAddComponent : public std::exception {
            public:
                CouldNotAddComponent();
                ~CouldNotAddComponent();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !COULDNOTADDCOMPONENT_HPP_ */
