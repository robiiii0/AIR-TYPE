/*
** EPITECH PROJECT, 2023
** output
** File description:
** SocketNotCreatedException
*/

#include "SocketNotCreatedException.hpp"

Engine::Network::SocketNotCreatedException::SocketNotCreatedException() {}

Engine::Network::SocketNotCreatedException::~SocketNotCreatedException() {}

const char *Engine::Network::SocketNotCreatedException::what() const throw() {
    return "Error: socket creation failed.";
}
