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
#include <unistd.h>

#include <cstdint>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "Client/Client.hpp"
#include "Messaging/Messager.hpp"
#include "enums/NetworkingTypeEnum.hpp"
#include "exceptions/ClientDisconnectedException/ClientDisconnectedException.hpp"
#include "exceptions/ClientIdOutOfRangeException/ClientIdOutOfRangeException.hpp"
#include "exceptions/CouldNotAcceptClientException/CouldNotAcceptClientException.hpp"
#include "exceptions/CouldNotBindAddressException/CouldNotBindAddressException.hpp"
#include "exceptions/CouldNotSendException/CouldNotSendException.hpp"
#include "exceptions/SocketNotCreatedException/SocketNotCreatedException.hpp"

namespace Engine {
    namespace Network {
        class NetworkingModule {
            public:
                NetworkingModule(int port, NetworkingTypeEnum type,
                                 int max_clients = 4);
                ~NetworkingModule();

                // Should be called in a thread, will automatically accept and
                // retrieve messages from clients
                void                run();
                void                sendMessage(const std::string &message,
                                                const std::size_t &client_id);
                std::vector<Client> getClients() const;

            protected:
            private:
                NetworkingTypeEnum                   _type;
                int                                  _socket_fd;
                struct sockaddr_in                   _server_address;
                std::vector<Engine::Network::Client> _clients;
                int                                  _max_clients;
                const uint8_t                        _protocol_prefix = 0xAA;
                const uint8_t                        _protocol_suffix = 0xBB;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !NETWORKINGMODULE_HPP_ */
