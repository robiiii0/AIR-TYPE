/*
** EPITECH PROJECT, 2023
** output
** File description:
** NetworkingModule
*/

#include "NetworkingModule.hpp"

Engine::Network::NetworkingModule::NetworkingModule(int                port,
                                                    NetworkingTypeEnum type) {
    switch (type) {
        case TCP:
            _socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            break;
        case UDP:
            _socket_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            break;
    }
    if (_socket_fd == -1) {
        throw SocketNotCreatedException();
    }
    _server_address.sin_family = AF_INET;
    _server_address.sin_addr.s_addr = INADDR_ANY;
    _server_address.sin_port = htons(port);
    if (bind(_socket_fd, (struct sockaddr *)&_server_address,
             sizeof(_server_address)) < 0) {
        throw CouldNotBindAddressException();
    }
}

Engine::Network::NetworkingModule::~NetworkingModule() {}

int Engine::Network::NetworkingModule::send(std::string message,
                                            int         client_id) {
    return 0;
}

std::vector<Engine::Network::Client>
    Engine::Network::NetworkingModule::getClients() const {
    return _clients;
}
