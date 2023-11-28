/*
** EPITECH PROJECT, 2023
** output
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <arpa/inet.h>
#include <netinet/in.h>

#include <string>

namespace Engine {
    namespace Network {
        class Client {
            public:
                Client(const std::string &ip, const int &port);
                ~Client();

                struct sockaddr_in getAddress() const;
                std::size_t        getId() const;

            protected:
            private:
                inline std::size_t getClientId() noexcept;
                static std::size_t _id;
                struct sockaddr_in _address;
        };

        std::size_t Client::_id = 0;
    };  // namespace Network
};      // namespace Engine

#endif /* !CLIENT_HPP_ */
