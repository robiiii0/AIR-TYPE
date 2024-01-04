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
    _running_thread =
        std::thread(&Engine::Network::NetworkingModule::run, this);
}

Engine::Network::NetworkingModule::NetworkingModule(
    int port, NetworkingTypeEnum type, const std::string &server_address,
    int server_port, int max_clients) :
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
    _running_thread =
        std::thread(&Engine::Network::NetworkingModule::run, this);
    struct sockaddr_in final_server_address;
    final_server_address.sin_family = AF_INET;
    final_server_address.sin_addr.s_addr = inet_addr(server_address.c_str());
    final_server_address.sin_port = htons(server_port);
    addClient(final_server_address);
}

Engine::Network::NetworkingModule::~NetworkingModule() {
    if (_socket_fd != 1) close(_socket_fd);
    _running_thread.join();
}

void Engine::Network::NetworkingModule::run() {
    Engine::Network::Messager messager(_type);
    while (true) {
        if (_type == TCP) {
            runTCP(messager);
        } else {
            runUDP(messager);
        }
    }
}

void Engine::Network::NetworkingModule::addClient(
    const struct sockaddr_in &client_address) {
    Engine::Network::Client client(client_address, 0);  // ! Only works for UDP
    _clients.push_back(client);
}

void Engine::Network::NetworkingModule::runTCP(
    Engine::Network::Messager &messager) {
    struct sockaddr_in client_address;
    socklen_t          client_address_size = sizeof(client_address);
    int                client_socket_fd = accept(
        _socket_fd, (struct sockaddr *)&client_address, &client_address_size);
    if (client_socket_fd < 0) {
        throw CouldNotAcceptClientException();
    } else {
        Engine::Network::Client client(client_address, _socket_fd);
        messager.startReceiving(client);
        _clients.push_back(client);
    }
}

void Engine::Network::NetworkingModule::runUDP(
    Engine::Network::Messager &messager) {
    char               buffer[16384];
    struct sockaddr_in client_address;
    socklen_t          client_address_size = sizeof(client_address);
    std::size_t        bytesReceived = 0;

    bytesReceived =
        recvfrom(_socket_fd, buffer, sizeof(buffer), 0,
                 (struct sockaddr *)&client_address, &client_address_size);

    std::cout << "Received " << bytesReceived << " bytes" << std::endl;
    if (bytesReceived == static_cast<std::size_t>(-1)) {
        perror("recvfrom error");
        std::cerr << "Error: " << (errno) << std::endl;
        throw CouldNotReceiveException();
    } else {
        if (isNewClient(client_address)) {
            Engine::Network::Client client(client_address, 0);
            std::string             message = buffer;
            _clients.push_back(client);  // TODO: décoder base64
            client.getBuffer()->write(buffer, bytesReceived);
        } else {
            addMessageToClientBuffer(buffer, bytesReceived, client_address);
        }
    }
}

bool Engine::Network::NetworkingModule::isNewClient(
    const struct sockaddr_in &client_address) {
    for (const auto &client : _clients) {
        if (client.getAddress().sin_addr.s_addr ==
                client_address.sin_addr.s_addr &&
            client.getAddress().sin_port == client_address.sin_port) {
            return false;
        }
    }
    return true;
}

void Engine::Network::NetworkingModule::addMessageToClientBuffer(
    const char *buffer, std::size_t &bytesReceived,
    const struct sockaddr_in &client_address) {
    for (auto &client : _clients) {
        if (client.getAddress().sin_addr.s_addr ==
                client_address.sin_addr.s_addr &&
            client.getAddress().sin_port == client_address.sin_port) {
            client.getBuffer()->write(buffer, bytesReceived);
            break;
        }
    }
}

std::string Engine::Network::NetworkingModule::encodeBase64(
    const std::string &input) {
    // Définition de la table de codage base64
    const char *base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Initialisation de la chaîne de sortie
    std::string output;

    // Conversion des octets de la chaîne d'entrée en base64
    for (size_t i = 0; i < input.size(); i += 3) {
        // Concaténation de trois octets en un entier de 24 bits
        uint8_t  byte1 = input[i];
        uint8_t  byte2 = (i + 1 < input.size()) ? input[i + 1] : 0;
        uint8_t  byte3 = (i + 2 < input.size()) ? input[i + 2] : 0;
        uint32_t value = (byte1 << 16) | (byte2 << 8) | byte3;

        // Conversion de l'entier de 24 bits en base64
        output += base64_chars[value >> 18];
        output += base64_chars[(value >> 12) & 0x3F];
        output += base64_chars[(value >> 6) & 0x3F];
        output += base64_chars[value & 0x3F];
    }

    // Retrait des caractères de remplissage "="
    if (output.size() % 4 == 2) {
        output += "==";
    } else if (output.size() % 4 == 3) {
        output += "=";
    }

    return output;
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
    std::string packet = "";
    packet += _protocol_prefix;
    packet += message;
    packet += _protocol_suffix;  // TODO: encoder en base64
    // std::cout << "Before " << sizeof(packet.length()) << "\n" << packet << std::endl;
    // packet = encodeBase64(packet);
    // std::cout << "After " << sizeof(packet.length()) << "\n" << packet << std::endl;
    // std::cout << "Sending " << packet << std::endl;
    messager.sendMessage(packet, _clients[index], _socket_fd);
}

void Engine::Network::NetworkingModule::broadcastMessage(
    const std::string &message) {
    Engine::Network::Messager messager(_type);
    std::string               packet = "";
    // packet += _protocol_prefix;
    packet += message;
    // packet += _protocol_suffix;
    for (auto &client : _clients) {
        if (!client.isConnected()) {
            continue;
        }
        sendMessage(packet, client.getId());
    }
}

std::vector<Engine::Network::Client> &
    Engine::Network::NetworkingModule::getClients() noexcept {
    return _clients;
}

Engine::Network::Serializer::Serializer &
    Engine::Network::NetworkingModule::getSerializer() noexcept {
    return _serializer;
}
