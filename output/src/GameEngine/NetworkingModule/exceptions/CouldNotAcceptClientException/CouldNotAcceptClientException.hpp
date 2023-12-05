/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotAcceptClientException
*/

#ifndef COULDNOTACCEPTCLIENTEXCEPTION_HPP_
#define COULDNOTACCEPTCLIENTEXCEPTION_HPP_

#include <exception>

namespace Engine {
    namespace Network {
        class CouldNotAcceptClientException : public std::exception {
            public:
                CouldNotAcceptClientException();
                ~CouldNotAcceptClientException();

                const char *what() const noexcept override;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !COULDNOTACCEPTCLIENTEXCEPTION_HPP_ */
