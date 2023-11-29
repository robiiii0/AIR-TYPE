/*
** EPITECH PROJECT, 2023
** output
** File description:
** ClientDisconnectedException
*/

#include "ClientDisconnectedException.hpp"

Engine::Network::ClientDisconnectedException::ClientDisconnectedException() {}

Engine::Network::ClientDisconnectedException::~ClientDisconnectedException() {}

const char *Engine::Network::ClientDisconnectedException::what()
    const noexcept {
    return "Client disconnected";
}
