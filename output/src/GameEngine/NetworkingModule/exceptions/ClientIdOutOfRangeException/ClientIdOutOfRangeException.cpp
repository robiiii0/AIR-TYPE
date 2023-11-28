/*
** EPITECH PROJECT, 2023
** output
** File description:
** ClientIdOutOfRangeException
*/

#include "ClientIdOutOfRangeException.hpp"

Engine::Network::ClientIdOutOfRangeException::ClientIdOutOfRangeException()
{
}

Engine::Network::ClientIdOutOfRangeException::~ClientIdOutOfRangeException()
{
}

const char *Engine::Network::ClientIdOutOfRangeException::what() const throw()
{
    return "Client id is out of range";
}
