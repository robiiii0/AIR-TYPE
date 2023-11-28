/*
** EPITECH PROJECT, 2023
** output
** File description:
** Buffer
*/

#include "Buffer.hpp"

Engine::Network::Buffer::Buffer() : _read_head(0), _write_head(0) {}

Engine::Network::Buffer::~Buffer() {}

void Engine::Network::Buffer::write(const char *message, const std::size_t &length) {
    for (std::size_t i = 0; i < length; i++) {
        _buffer[_write_head] = message[i];
        _write_head++;
    }
}

void Engine::Network::Buffer::write(const std::string &message) {
    for (std::size_t i = 0; i < message.size(); i++) {
        _buffer[_write_head] = message[i];
        _write_head++;
    }
}

std::string Engine::Network::Buffer::read() {
    std::string message;

    for (std::size_t i = _read_head; i < _write_head; i++) {
        message += _buffer[i];
    }
    _read_head = _write_head;
    return message;
}

std::string Engine::Network::Buffer::read(const int &length) {
    std::string message;

    for (std::size_t i = _read_head; i < _read_head + length; i++) {
        message += _buffer[i];
    }
    _read_head += length;
    return message;
}

std::string Engine::Network::Buffer::readNextPacket() {
    std::string message;
    std::size_t start = 5000;
    std::size_t end = 5000;

    for (std::size_t i = _read_head; i < _write_head; i++) {
        if (_buffer[i] == _protocol_prefix) {
            start = i;
        }
        if (_buffer[i] == _protocol_suffix) {
            end = i;
            break;
        }
    }
    if (start > 4096 && end > 4096) {
        return "";
    }
    for (std::size_t i = start + 1; i < end; i++) {
        message += _buffer[i];
    }
    _read_head = end + 1;
    return message;
}
