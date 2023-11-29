/*
** EPITECH PROJECT, 2023
** output
** File description:
** Client
*/

#include "Client.hpp"

Engine::Network::Client::Client(const std::string &ip, const int &port,
                                const int &socket_fd) :
    _socket_fd(socket_fd) {
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = inet_addr(ip.c_str());
    _address.sin_port = htons(port);
    _id = getClientId();
    _is_threaded = false;
    _is_connected = true;
}

Engine::Network::Client::~Client() {
    close(_socket_fd);
}

struct sockaddr_in Engine::Network::Client::getAddress() const {
    return _address;
}

std::size_t Engine::Network::Client::getId() const { return _id; }

Engine::Network::Buffer &Engine::Network::Client::getBuffer() {
    return _buffer;
}

int Engine::Network::Client::getSocketFd() const { return _socket_fd; }

bool Engine::Network::Client::isThreaded() const { return _is_threaded; }

bool Engine::Network::Client::isConnected() const { return _is_connected; }

void Engine::Network::Client::setConnected(bool connected) {
    _is_connected = connected;
}

void Engine::Network::Client::setThreaded(bool threaded) {
    _is_threaded = threaded;
}

// TODO: Test if this works
inline std::size_t Engine::Network::Client::getClientId() noexcept {
    return _id++;
}
