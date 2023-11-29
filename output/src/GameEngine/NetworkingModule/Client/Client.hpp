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

#include <memory>
#include <string>

#include "../Buffer/Buffer.hpp"

namespace Engine {
    namespace Network {
        class Client {
            public:
                Client(struct sockaddr_in address, const int socket_fd);
                ~Client();

                struct sockaddr_in                       getAddress() const;
                std::size_t                              getId() const;
                std::shared_ptr<Engine::Network::Buffer> getBuffer();
                int                                      getSocketFd() const;
                bool                                     isThreaded() const;
                bool                                     isConnected() const;

                void setConnected(bool connected);
                void setThreaded(bool threaded);

            protected:
            private:
                std::size_t                              getClientId() noexcept;
                static int                               __max_client_id;
                std::size_t                              _id;
                struct sockaddr_in                       _address;
                std::shared_ptr<Engine::Network::Buffer> _buffer;
                int                                      _socket_fd;
                bool                                     _is_threaded;
                bool                                     _is_connected;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !CLIENT_HPP_ */
