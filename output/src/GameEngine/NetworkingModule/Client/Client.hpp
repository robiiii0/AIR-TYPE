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
#include <unistd.h>

#include <string>

#include "../Buffer/Buffer.hpp"

namespace Engine {
    namespace Network {
        class Client {
            public:
                Client(const std::string &ip, const int &port,
                       const int &socket_fd);
                ~Client();

                struct sockaddr_in       getAddress() const;
                std::size_t              getId() const;
                Engine::Network::Buffer &getBuffer();
                int                      getSocketFd() const;
                bool                     isThreaded() const;
                bool                     isConnected() const;

                void setConnected(bool connected);
                void setThreaded(bool threaded);

            protected:
            private:
                inline std::size_t      getClientId() noexcept;
                static std::size_t      _id;
                struct sockaddr_in      _address;
                Engine::Network::Buffer _buffer;
                int                     _socket_fd;
                bool                    _is_threaded;
                bool                    _is_connected;
        };

        std::size_t Client::_id = 0;
    };  // namespace Network
};      // namespace Engine

#endif /* !CLIENT_HPP_ */
