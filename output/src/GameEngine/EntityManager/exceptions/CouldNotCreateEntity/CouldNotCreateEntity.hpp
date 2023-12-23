/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotCreateEntity
*/

#ifndef COULDNOTCREATEENTITY_HPP_
#define COULDNOTCREATEENTITY_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class CouldNotCreateEntity : public std::exception {
            public:
                CouldNotCreateEntity();
                ~CouldNotCreateEntity();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !COULDNOTCREATEENTITY_HPP_ */
