/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotReceiveException
*/

#include "CouldNotReceiveException.hpp"

Engine::Network::CouldNotReceiveException::CouldNotReceiveException() {}

Engine::Network::CouldNotReceiveException::~CouldNotReceiveException() {}

const char* Engine::Network::CouldNotReceiveException::what() const noexcept
{
    return "Could not receive message";
}
