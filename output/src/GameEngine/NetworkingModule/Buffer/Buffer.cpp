/*
** EPITECH PROJECT, 2023
** output
** File description:
** Buffer
*/

#include "Buffer.hpp"

Engine::Network::Buffer::Buffer() : _read_head(0), _write_head(0) {}

Engine::Network::Buffer::~Buffer() {}

void Engine::Network::Buffer::write(const char        *message,
                                    const std::size_t &length) {
    for (std::size_t i = 0; i < length; i++) {
        _buffer[_write_head++] = message[i];
        _write_head %= __circular_buffer_size;
    }
}

void Engine::Network::Buffer::write(const std::string &message) {
    write(message.c_str(), message.length());
}

std::string Engine::Network::Buffer::read() {
    std::string message;
    while (_read_head != _write_head) {
        message += _buffer[_read_head++];
        _read_head %= __circular_buffer_size;
    }
    return message;
}

std::string Engine::Network::Buffer::read(const int &length) {
    std::string message;

    for (int i = 0; i < length && _read_head != _write_head; i++) {
        message += _buffer[_read_head++];
        _read_head %= __circular_buffer_size;
    }
    return message;
}

std::string Engine::Network::Buffer::readNextPacket() {
    std::string packet;

    while (_read_head != _write_head) {
        char c = _buffer[_read_head++];
        if (c == _protocol_suffix) {
            break;
        } else {
            packet += c;
        }
        _read_head %= __circular_buffer_size;
    }
    return packet;
}

bool Engine::Network::Buffer::hasPacket() {
    for (std::size_t i = _read_head; i != _write_head; i++) {
        if (i == __circular_buffer_size) {
            i = 0;
        }
        if (_buffer[i] == (char)_protocol_suffix) {
            return true;
        }
    }
    return false;
}
