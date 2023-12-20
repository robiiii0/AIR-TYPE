/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotAddEntity
*/

#ifndef COULDNOTADDENTITY_HPP_
#define COULDNOTADDENTITY_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class CouldNotAddEntity : public std::exception {
            public:
                CouldNotAddEntity();
                ~CouldNotAddEntity();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !COULDNOTADDENTITY_HPP_ */
