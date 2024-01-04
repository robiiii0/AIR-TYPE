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
    std::lock_guard<std::mutex> lock(_mutex);
    for (std::size_t i = 0; i < length; i++) {
        _buffer[_write_head++] = message[i];
        _write_head %= __circular_buffer_size;
    }
}

void Engine::Network::Buffer::write(const std::string &message) {
    write(message.c_str(), message.length());
}

std::string Engine::Network::Buffer::read() {
    std::lock_guard<std::mutex> lock(_mutex);
    std::string message;
    while (_read_head != _write_head) {
        message += _buffer[_read_head++];
        _read_head %= __circular_buffer_size;
    }
    return message;
}

std::string Engine::Network::Buffer::read(const int &length) {
    std::lock_guard<std::mutex> lock(_mutex);
    std::string message;

    for (int i = 0; i < length && _read_head != _write_head; i++) {
        message += _buffer[_read_head++];
        _read_head %= __circular_buffer_size;
    }
    return message;
}

std::string Engine::Network::Buffer::readNextPacket() {
    std::lock_guard<std::mutex> lock(_mutex);
    std::string packet;
    bool        isPacket = false;

    while (_read_head != _write_head) {
        char c = _buffer[_read_head++];
        if (isPrefix(_read_head)) {
            _read_head += _protocol_prefix.length() - 1;
            isPacket = true;
        } else if (isSuffix(_read_head) && isPacket) {
            _read_head += _protocol_suffix.length();
            packet += c;
            break;
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
    std::lock_guard<std::mutex> lock(_mutex);
    bool isPacket = false;
    std::cout << "buffer content:" << std::endl;
    for (std::size_t i = _read_head; i != _write_head; i++) {
        std::cout << _buffer[i];
        i %= __circular_buffer_size;
    }
    std::cout << std::endl;
    // while (!isPrefix(_read_head) && _read_head != _write_head) {
    //     _read_head++;
    //     _read_head %= __circular_buffer_size;
    // }
    for (std::size_t i = _read_head; i != _write_head; i++) {
        if (i == __circular_buffer_size) {
            i = 0;
        }
        if (isPrefix(i)) {
            i += _protocol_prefix.length() - 1;
            isPacket = true;
        } else if (isSuffix(i) && isPacket) {
            return true;
        }
    }
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
