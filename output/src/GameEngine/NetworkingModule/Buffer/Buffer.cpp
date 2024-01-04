/*
** EPITECH PROJECT, 2023
** output
** File description:
** Buffer
*/

#include "Buffer.hpp"
#include "../Serializer/Serializer.hpp"

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
        char c = _buffer[_read_head];
        if (isPrefix(_read_head)) {
            _read_head += _protocol_prefix.length();
            isPacket = true;
        } else if (isSuffix(_read_head) && isPacket) {
            break;
        } else if (isSuffix(_read_head) && !isPacket) {
            packet = "";
        } else if (isPacket) {
            packet += c;
        }
    }
    if (_read_head == _write_head) {
        clear();
    }
    return packet;
}

bool Engine::Network::Buffer::hasPacket() {
    bool isPacket = false;

    while (!isPrefix(_read_head) && _read_head != _write_head) {
        _read_head++;
        _read_head %= __circular_buffer_size;
    }
    for (std::size_t i = _read_head; i != _write_head; i++) {
        if (i == __circular_buffer_size) {
            i = 0;
        }
        if (isPrefix(i)) {
            isPacket = true;
        } else if (isSuffix(i) && isPacket) {
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

bool Engine::Network::Buffer::isPrefix(const std::size_t index) {
    for (std::size_t i = 0; i < _protocol_prefix.length(); i++) {
        if (_buffer[(index + i) % __circular_buffer_size] !=
            _protocol_prefix[i]) {
            return false;
        }
    }
    return true;
}

bool Engine::Network::Buffer::isSuffix(const std::size_t index) {
    for (std::size_t i = 0; i < _protocol_suffix.length(); i++) {
        if (_buffer[(index + i) % __circular_buffer_size] !=
            _protocol_suffix[i]) {
            return false;
        }
    }
    return true;
}
