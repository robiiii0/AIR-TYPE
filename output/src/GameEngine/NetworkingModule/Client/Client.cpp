/*
** EPITECH PROJECT, 2023
** output
** File description:
** Client
*/

#include "Client.hpp"

int Engine::Network::Client::__max_client_id = 0;

Engine::Network::Client::Client(sf::IpAddress ip_address, unsigned short port) :
    _is_threaded(false), _is_connected(true) {
    _id = getClientId();
    _ip_address = ip_address;
    _port = port;
    _buffer = std::make_shared<Engine::Network::Buffer>();
}

Engine::Network::Client::~Client() {}

sf::IpAddress Engine::Network::Client::getAddress() const {
    return _ip_address;
}

unsigned short Engine::Network::Client::getPort() const { return _port; }

std::size_t Engine::Network::Client::getId() const { return _id; }

std::shared_ptr<Engine::Network::Buffer> Engine::Network::Client::getBuffer() {
    return _buffer;
}

bool Engine::Network::Client::isThreaded() const { return _is_threaded; }

bool Engine::Network::Client::isConnected() const { return _is_connected; }

void Engine::Network::Client::setConnected(bool connected) {
    _is_connected = connected;
}

void Engine::Network::Client::setThreaded(bool threaded) {
    _is_threaded = threaded;
}

std::size_t Engine::Network::Client::getClientId() noexcept {
    return __max_client_id++;
}
