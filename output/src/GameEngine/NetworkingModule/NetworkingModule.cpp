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
    std::cout << "Running" << std::endl;
    while (true) {
        if (_type == TCP) {
            struct sockaddr_in client_address;
            socklen_t          client_address_size = sizeof(client_address);
            int                client_socket_fd =
                accept(_socket_fd, (struct sockaddr *)&client_address,
                       &client_address_size);
            if (client_socket_fd < 0) {
                throw CouldNotAcceptClientException();
            } else {
                Engine::Network::Client client(client_address, _socket_fd);
                messager.startReceiving(client);
                _clients.push_back(client);
            }
        } else {
            char               buffer[1024];
            struct sockaddr_in client_address;
            socklen_t          client_address_size = sizeof(client_address);
            std::size_t        bytesReceived = 0;

            bytesReceived = recvfrom(_socket_fd, buffer, sizeof(buffer), 0,
                                     (struct sockaddr *)&client_address,
                                     &client_address_size);

            if (bytesReceived == static_cast<std::size_t>(-1)) {
                perror("recvfrom error");
                std::cerr << "Error: " << (errno) << std::endl;
                throw CouldNotReceiveException();
            } else {
                std::cout << "Received " << bytesReceived << " bytes from "
                          << inet_ntoa(client_address.sin_addr) << ":"
                          << ntohs(client_address.sin_port) << std::endl;

                bool isNewClient = true;
                for (const auto &client : _clients) {
                    if (client.getAddress().sin_addr.s_addr ==
                            client_address.sin_addr.s_addr &&
                        client.getAddress().sin_port ==
                            client_address.sin_port) {
                        isNewClient = false;
                        break;
                    }
                }

                if (isNewClient) {
                    std::cout << "New client connected" << std::endl;
                    Engine::Network::Client client(client_address, 0);
                    std::string             message = buffer;
                    client.getBuffer()->write(buffer, bytesReceived);
                    _clients.push_back(client);
                } else {
                    for (auto &client : _clients) {
                        if (client.getAddress().sin_addr.s_addr ==
                                client_address.sin_addr.s_addr &&
                            client.getAddress().sin_port ==
                                client_address.sin_port) {
                            client.getBuffer()->write(buffer, bytesReceived);
                            break;
                        }
                    }
                }
            }
        }
    }
}

void Engine::Network::NetworkingModule::sendMessage(
    const std::string &message, const std::size_t &client_id) {
    Engine::Network::Messager messager(_type);
    int                       index = 0;
    if (client_id >= _clients.size()) {
        throw ClientIdOutOfRangeException();
    }
    for (auto &client : _clients) {
        if (client.getId() == client_id) {
            if (!client.isConnected()) {
                throw ClientDisconnectedException();
            } else {
                break;
            }
        }
        index++;
    }
    messager.sendMessage(message, _clients[index]);
}

std::vector<Engine::Network::Client>
    Engine::Network::NetworkingModule::getClients() const {
    return _clients;
}
