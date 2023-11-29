/*
** EPITECH PROJECT, 2023
** output
** File description:
** NetworkingModule
*/

#include "NetworkingModule.hpp"

Engine::Network::NetworkingModule::NetworkingModule(int                port,
                                                    NetworkingTypeEnum type,
                                                    int max_clients) :
    _max_clients(max_clients), _type(type) {
    _socket_fd = -1;
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

Engine::Network::NetworkingModule::~NetworkingModule() {
    if (_socket_fd != 1) close(_socket_fd);
}

void Engine::Network::NetworkingModule::run() {
    Engine::Network::Messager messager(_type);
    while (true) {
        struct sockaddr_in client_address;
        socklen_t          client_address_size = sizeof(client_address);
        int                client_socket_fd =
            accept(_socket_fd, (struct sockaddr *)&client_address,
                   &client_address_size);
        if (client_socket_fd < 0) {
            throw CouldNotAcceptClientException();
        } else {
            Engine::Network::Client client(inet_ntoa(client_address.sin_addr),
                                           ntohs(client_address.sin_port),
                                           client_socket_fd);
            messager.startReceiving(client);
            _clients.push_back(client);
            messager.startReceiving(_clients.back());
        }
    }
}

std::vector<Engine::Network::Client>
    Engine::Network::NetworkingModule::getClients() const {
    return _clients;
}
