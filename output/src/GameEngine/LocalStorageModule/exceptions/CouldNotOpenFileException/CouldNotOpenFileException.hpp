/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotOpenFileException
*/

#ifndef COULDNOTOPENFILEEXCEPTION_HPP_
#define COULDNOTOPENFILEEXCEPTION_HPP_

#include <exception>

namespace Engine {
    namespace LocalStorage {
        class CouldNotOpenFileException : public std::exception {
            public:
                CouldNotOpenFileException();
                ~CouldNotOpenFileException();
                const char* what() const noexcept override;
        };
    }  // namespace LocalStorage
}  // namespace Engine

#endif /* !COULDNOTOPENFILEEXCEPTION_HPP_ */
