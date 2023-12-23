/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** CouldNotFindEntity
*/

#ifndef COULDNOTFINDENTITY_HPP_
#define COULDNOTFINDENTITY_HPP_

#include <exception>

namespace Engine {
    namespace EntityManager {
        class CouldNotFindEntity : public std::exception {
            public:
                CouldNotFindEntity();
                ~CouldNotFindEntity();

                const char *what() const noexcept override;
        };
    };  // namespace EntityManager
};      // namespace Engine

#endif /* !COULDNOTFINDENTITY_HPP_ */
