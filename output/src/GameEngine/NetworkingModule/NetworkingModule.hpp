/*
** EPITECH PROJECT, 2023
** output
** File description:
** NetworkingModule
*/

#ifndef NETWORKINGMODULE_HPP_
#define NETWORKINGMODULE_HPP_

#include <netinet/in.h>
#include <sys/socket.h>

#include <iostream>
#include <string>
#include <vector>

#include "Client/Client.hpp"
#include "enums/NetworkingTypeEnum.hpp"
#include "exceptions/CouldNotBindAddressException/CouldNotBindAddressException.hpp"
#include "exceptions/SocketNotCreatedException/SocketNotCreatedException.hpp"

namespace Engine {
    namespace Network {
        class NetworkingModule {
            public:
                NetworkingModule(int port, NetworkingTypeEnum type);
                ~NetworkingModule();

                int                 send(std::string message, int client_id);
                std::vector<Client> getClients() const;

            protected:
            private:
                int                                  _socket_fd;
                struct sockaddr_in                   _server_address;
                std::vector<Engine::Network::Client> _clients;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !NETWORKINGMODULE_HPP_ */
