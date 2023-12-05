/*
** EPITECH PROJECT, 2023
** output
** File description:
** Client
*/

#include "Client.hpp"

// std::atomic<std::size_t> Engine::Network::Client::_id{0};
int Engine::Network::Client::__max_client_id = 0;

Engine::Network::Client::Client(struct sockaddr_in address,
                                const int          socket_fd) :
    _socket_fd(socket_fd),
    _is_threaded(false),
    _is_connected(true),
    _address(address) {
    _id = getClientId();
    _buffer = std::make_shared<Engine::Network::Buffer>();
}

Engine::Network::Client::~Client() { close(_socket_fd); }

struct sockaddr_in Engine::Network::Client::getAddress() const {
    return _address;
}

std::size_t Engine::Network::Client::getId() const { return _id; }

std::shared_ptr<Engine::Network::Buffer> Engine::Network::Client::getBuffer() {
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
std::size_t Engine::Network::Client::getClientId() noexcept {
    return __max_client_id++;
}
