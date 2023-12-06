/*
** EPITECH PROJECT, 2023
** output
** File description:
** Buffer
*/

#ifndef BUFFER_HPP_
#define BUFFER_HPP_

#include <array>
#include <cstdint>
#include <string>

namespace Engine {
    namespace Network {
        const std::size_t __circular_buffer_size = 4096;

        class Buffer {
            public:
                Buffer();
                ~Buffer();

                /*
                * @brief Write a message to the buffer
                * @param message The message to write
                * @param length The length of the message
                */
                void write(const char *message, const std::size_t &length);
                /*
                * @brief Write a message to the buffer
                * @param message The message to write
                */
                void write(const std::string &message);

                /*
                * @brief Read a message from the buffer
                * @return The whole message read
                */
                std::string read();
                /*
                * @brief Read a message from the buffer
                * @param length The length of the message to read
                * @return The message read
                */
                std::string read(const int &length);
                /*
                * @brief Read a packet from the buffer, a packet is a message
                * that starts with 0xAA and ends with 0xBB
                * @return The message read
                */
                std::string readNextPacket();

            protected:
            private:
                std::array<char, __circular_buffer_size> _buffer;
                std::size_t                              _read_head;
                std::size_t                              _write_head;
                const uint8_t _protocol_prefix = 0xAA;
                const uint8_t _protocol_suffix = 0xBB;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !BUFFER_HPP_ */
