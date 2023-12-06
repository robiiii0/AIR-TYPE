/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotAcceptClientException
*/

#include "CouldNotAcceptClientException.hpp"

Engine::Network::CouldNotAcceptClientException::
    CouldNotAcceptClientException() {}

Engine::Network::CouldNotAcceptClientException::
    ~CouldNotAcceptClientException() {}

const char *Engine::Network::CouldNotAcceptClientException::what()
    const noexcept {
    return "Could not accept client";
}
