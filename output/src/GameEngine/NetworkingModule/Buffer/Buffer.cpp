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
    bool        isPacket = false;

    while (_read_head != _write_head) {
        char c = _buffer[_read_head++];
        if (c == _protocol_prefix) {
            isPacket = true;
        } else if (c == _protocol_suffix && isPacket) {
            break;
        } else if (c == _protocol_suffix && !isPacket) {
            packet = "";
        } else if (isPacket) {
            packet += c;
        }
    }
    if (_read_head == _write_head) {
        _read_head = 0;
        _write_head = 0;
        _buffer.fill(0);
    }
    return packet;
}

bool Engine::Network::Buffer::hasPacket() {
    bool isPacket = false;

    while (_buffer[_read_head] != _protocol_prefix && _read_head != _write_head) {
        _read_head++;
        _read_head %= __circular_buffer_size;
    }
    for (std::size_t i = _read_head; i != _write_head; i++) {
        if (i == __circular_buffer_size) {
            i = 0;
        }
        if (_buffer[i] == _protocol_prefix) {
            isPacket = true;
        } else if (_buffer[i] == _protocol_suffix && isPacket) {
            return true;
        }
    }
    clear();
    return false;
}

void Engine::Network::Buffer::clear() {
    _read_head = 0;
    _write_head = 0;
    _buffer.fill(0);
}
