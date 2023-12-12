# Buffer - Networking Buffer

## Overview

The `Buffer` class is a component within the R-Type project designed to handle message buffering for networking purposes. This class implements a circular buffer that allows for writing and reading messages efficiently. Additionally, it provides methods to read messages based on specific criteria, such as message length or packet delimiters.

## Structure Explanation

### `Buffer` Class

```cpp
class Buffer {
public:
    Buffer();
    ~Buffer();

    void write(const char *message, const std::size_t &length);
    void write(const std::string &message);

    std::string read();
    std::string read(const int &length);
    std::string readNextPacket();

protected:
private:
    std::array<char, __circular_buffer_size> _buffer;
    std::size_t                              _read_head;
    std::size_t                              _write_head;
    const uint8_t _protocol_prefix = 0xAA;
    const uint8_t _protocol_suffix = 0xBB;
};
```

#### Public Methods

- **Constructor and Destructor**:
  - `Buffer()`: Constructor for initializing the `Buffer` instance.
  - `~Buffer()`: Destructor for cleanup.

- `void write(const char *message, const std::size_t &length)`: Method to write a message to the buffer given the message and its length.
- `void write(const std::string &message)`: Overloaded method to write a string message to the buffer.

- `std::string read()`: Method to read the whole message from the buffer.
- `std::string read(const int &length)`: Method to read a specific length of the message from the buffer.
- `std::string readNextPacket()`: Method to read a packet from the buffer, where a packet is defined to start with `0xAA` and end with `0xBB`.

#### Private Members

- `std::array<char, __circular_buffer_size> _buffer`: Circular buffer to store messages.
- `std::size_t _read_head`: Index indicating the read position in the buffer.
- `std::size_t _write_head`: Index indicating the write position in the buffer.
- `const uint8_t _protocol_prefix`: Prefix byte of the packet protocol (start of packet).
- `const uint8_t _protocol_suffix`: Suffix byte of the packet protocol (end of packet).

## Usage

The `Buffer` class is designed to be used for networking within the R-Type project. It provides methods to write and read messages efficiently. The `readNextPacket` method is particularly useful for reading packets in a network stream that are demarcated by specific prefix and suffix bytes.

### Example Usage

```cpp
#include "Buffer.hpp"

// Example usage with a Buffer
Engine::Network::Buffer buffer;

// Writing a message to the buffer
buffer.write("Hello, R-Type!");

// Reading the entire message from the buffer
std::string message = buffer.read();

// Reading the next packet from the buffer
std::string packet = buffer.readNextPacket();
```

In this example, a `Buffer` instance is created, and a message is written to the buffer. The entire message is then read from the buffer. Additionally, the `readNextPacket` method is used to read the next packet from the buffer, where packets are defined to start with `0xAA` and end with `0xBB`. Customize the usage according to the networking requirements of your project.