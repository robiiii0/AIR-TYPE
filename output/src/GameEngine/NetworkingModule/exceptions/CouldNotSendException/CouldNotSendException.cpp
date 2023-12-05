/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotSendException
*/

#include "CouldNotSendException.hpp"

Engine::Network::CouldNotSendException::CouldNotSendException(
    Engine::Network::Client client) :
    _client(client) {}

Engine::Network::CouldNotSendException::~CouldNotSendException() {}

const char *Engine::Network::CouldNotSendException::what() const throw() {
    std::string str = "Could not send data to ";
    str += _client.getAddress().sin_addr.s_addr;
    str += "!";

    return str.c_str();
}
