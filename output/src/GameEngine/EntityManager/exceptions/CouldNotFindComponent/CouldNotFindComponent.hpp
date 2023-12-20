/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotFindComponent
*/

#ifndef COULDNOTFINDCOMPONENT_HPP_
#define COULDNOTFINDCOMPONENT_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class CouldNotFindComponent : public std::exception {
            public:
                CouldNotFindComponent();
                ~CouldNotFindComponent();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !COULDNOTFINDCOMPONENT_HPP_ */
