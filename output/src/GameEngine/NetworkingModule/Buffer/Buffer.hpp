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

namespace Engine
{
namespace Network
{
const std::size_t __circular_buffer_size = 4096;

class Buffer {
   public:
    Buffer();
    ~Buffer();

    void write(const char* message, const std::size_t& length);
    void write(const std::string& message);

    std::string read();
    std::string read(const int& length);
    std::string readNextPacket();

   protected:
   private:
    std::array<char, __circular_buffer_size> _buffer;
    std::size_t _read_head;
    std::size_t _write_head;
    const uint8_t _protocol_prefix = 0xAA;
    const uint8_t _protocol_suffix = 0xBB;
};
};  // namespace Network
};  // namespace Engine

#endif /* !BUFFER_HPP_ */
