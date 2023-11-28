/*
** EPITECH PROJECT, 2023
** output
** File description:
** Client
*/

#include "Client.hpp"

Engine::Network::Client::Client(const std::string &ip, const int &port) {
    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = inet_addr(ip.c_str());
    _address.sin_port = htons(port);
    _id = getClientId();
}

Engine::Network::Client::~Client() {}

struct sockaddr_in Engine::Network::Client::getAddress() const {
    return _address;
}

std::size_t Engine::Network::Client::getId() const { return _id; }

// TODO: Test if this works
inline std::size_t Engine::Network::Client::getClientId() noexcept {
    return _id++;
}
