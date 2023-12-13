# Client - Networking Client

## Overview

The `Client` class is a component within the R-Type project designed to represent a networking client. This class encapsulates client-related functionalities, such as managing client information, communication buffers, socket file descriptor, and connection state.

## Structure Explanation

### `Client` Class

```cpp
class Client {
public:
    Client(struct sockaddr_in address, const int socket_fd);
    ~Client();

    struct sockaddr_in getAddress() const;
    std::size_t getId() const;
    std::shared_ptr<Engine::Network::Buffer> getBuffer();
    int getSocketFd() const;
    bool isThreaded() const;
    bool isConnected() const;

    void setConnected(bool connected);
    void setThreaded(bool threaded);

protected:
private:
    std::size_t                              getClientId() noexcept;
    static int                               __max_client_id;
    std::size_t                              _id;
    struct sockaddr_in                       _address;
    std::shared_ptr<Engine::Network::Buffer> _buffer;
    int                                      _socket_fd;
    bool                                     _is_threaded;
    bool                                     _is_connected;
};
```

#### Public Methods

- **Constructor and Destructor**:
  - `Client(struct sockaddr_in address, const int socket_fd)`: Constructor for initializing the `Client` instance with a given address and socket file descriptor.
  - `~Client()`: Destructor for cleanup.

- `struct sockaddr_in getAddress() const`: Method to get the address of the client.
- `std::size_t getId() const`: Method to get the unique identifier of the client.
- `std::shared_ptr<Engine::Network::Buffer> getBuffer()`: Method to get the buffer associated with the client.
- `int getSocketFd() const`: Method to get the socket file descriptor of the client.
- `bool isThreaded() const`: Method to check if the client is threaded.
- `bool isConnected() const`: Method to check if the client is connected.

- `void setConnected(bool connected)`: Method to set the connection state of the client.
- `void setThreaded(bool threaded)`: Method to set whether the client is threaded.

#### Private Members

- `std::size_t _id`: Unique identifier for the client.
- `struct sockaddr_in _address`: Address information of the client.
- `std::shared_ptr<Engine::Network::Buffer> _buffer`: Shared pointer to the communication buffer associated with the client.
- `int _socket_fd`: Socket file descriptor of the client.
- `bool _is_threaded`: Boolean indicating whether the client is threaded.
- `bool _is_connected`: Boolean indicating whether the client is connected.

#### Static Members

- `static int __max_client_id`: Static variable to track the maximum client ID across all instances.

## Usage

The `Client` class is designed to be used for managing client-related information within the R-Type project. It provides methods to access and manipulate client properties, such as ID, address, buffer, socket file descriptor, and connection state.

### Example Usage

```cpp
#include "Client.hpp"

// Example usage with a Client
struct sockaddr_in clientAddress;
// ... initialize clientAddress ...

int clientSocketFd = // ... initialize client socket file descriptor ...

// Create a Client instance
Engine::Network::Client client(clientAddress, clientSocketFd);

// Access client properties
std::size_t clientId = client.getId();
struct sockaddr_in clientAddr = client.getAddress();
int clientSocket = client.getSocketFd();
bool isConnected = client.isConnected();

// Modify client properties
client.setThreaded(true);
client.setConnected(false);
```

In this example, a `Client` instance is created with an initialized address and socket file descriptor. Properties of the client, such as ID, address, socket file descriptor, and connection state, are accessed and modified using the provided methods. Customize the usage according to the networking requirements of your project.