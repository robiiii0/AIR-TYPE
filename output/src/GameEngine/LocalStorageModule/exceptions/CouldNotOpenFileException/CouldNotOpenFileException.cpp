/*
** EPITECH PROJECT, 2023
** output
** File description:
** CouldNotOpenFileException
*/

#include "CouldNotOpenFileException.hpp"

Engine::LocalStorage::CouldNotOpenFileException::CouldNotOpenFileException() {}

Engine::LocalStorage::CouldNotOpenFileException::~CouldNotOpenFileException() {}

const char* Engine::LocalStorage::CouldNotOpenFileException::what()
    const noexcept
{
    return "Could not open file";
}
