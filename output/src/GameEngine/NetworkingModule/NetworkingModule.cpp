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

Engine::Network::NetworkingModule::~NetworkingModule() { close(_socket_fd); }

int Engine::Network::NetworkingModule::send(std::string message,
                                            std::size_t client_id) {
    int index = -1;
    std::string msg = std::to_string(_protocol_prefix) + message +
                      std::to_string(_protocol_suffix);

    if (client_id > 0) {
        throw ClientIdOutOfRangeException();
    }
    for (int i = 0; i < _clients.size(); i++) {
        if (_clients[i].getId() == client_id) index = i;
    }
    if (index == -1) throw ClientIdOutOfRangeException();
    if (sendto(_socket_fd, message.c_str(), message.size(), 0,
               (struct sockaddr *)&_clients[index].getAddress(),
               sizeof(_clients[index].getAddress())) < 0)
        throw CouldNotSendException(_clients[index]);
    return 0;
}

std::vector<Engine::Network::Client>
    Engine::Network::NetworkingModule::getClients() const {
    return _clients;
}
