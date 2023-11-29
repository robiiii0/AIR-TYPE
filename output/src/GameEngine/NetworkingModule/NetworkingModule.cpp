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
    _max_clients(max_clients) {
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

int Engine::Network::NetworkingModule::send(std::string message,
                                            std::size_t client_id) {
    int         index = -1;
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

std::string Engine::Network::NetworkingModule::receive(std::size_t client_id) {
    int         index = -1;
    char        buffer[5000] = {0};
    std::string message;

    if (client_id > 0) {
        throw ClientIdOutOfRangeException();
    }
    for (int i = 0; i < _clients.size(); i++) {
        if (_clients[i].getId() == client_id) index = i;
    }
    if (index == -1) throw ClientIdOutOfRangeException();
    return _clients[index].getBuffer().readNextPacket();
}

std::vector<Engine::Network::Client>
    Engine::Network::NetworkingModule::getClients() const {
    return _clients;
}

// TODO: Test if this works
void Engine::Network::NetworkingModule::handleConnections() {
    while (true) {
        struct sockaddr_in client_address;
        socklen_t          client_address_size = sizeof(client_address);
        int                client_socket_fd =
            accept(_socket_fd, (struct sockaddr *)&client_address,
                   (socklen_t *)&client_address_size);
        if (client_socket_fd < 0) {
            throw std::exception();  // TODO: Create exception
        }
        std::string ip = inet_ntoa(client_address.sin_addr);
        _clients.push_back(
            Client(ip, ntohs(client_address.sin_port), client_socket_fd));
        for (auto &client : _clients) {
            if (client.isThreaded() == false) {
                std::thread thread(&NetworkingModule::handleRetrieval, client);
                thread.detach();
            }
        }
    }
}

// TODO: Test if this works
void Engine::Network::NetworkingModule::handleRetrieval(
    Engine::Network::Client &client) {
    char buffer[1024] = {0};

    while (true) {
        int val_read = recv(client.getSocketFd(), buffer, sizeof(buffer), 0);

        if (val_read == 0) {
            close(client.getSocketFd());
            break;
        } else if (val_read < 0) {
            throw std::exception();  // TODO: Create exception
        }
        client.getBuffer().write(buffer, val_read);
    }
}
