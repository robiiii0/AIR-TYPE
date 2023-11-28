/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotSendException
*/

#ifndef COULDNOTSENDEXCEPTION_HPP_
#define COULDNOTSENDEXCEPTION_HPP_

#include <exception>

#include "../Client/Client.hpp"

namespace Engine {
    namespace Network {
        class CouldNotSendException : public std::exception {
            public:
                CouldNotSendException(Engine::Network::Client client);
                ~CouldNotSendException();

                const char *what() const throw() override;

            protected:
            private:
                Client _client;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !COULDNOTSENDEXCEPTION_HPP_ */
