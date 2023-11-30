/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotBindAddressException
*/

#include "CouldNotBindAddressException.hpp"

Engine::Network::CouldNotBindAddressException::CouldNotBindAddressException() {}

Engine::Network::CouldNotBindAddressException::~CouldNotBindAddressException()
{}

const char* Engine::Network::CouldNotBindAddressException::what() const throw()
{
    return "Error: could not bind address.";
}
