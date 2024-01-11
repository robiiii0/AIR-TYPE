# Networking Module

## Description

This module is responsible for the communication between the server and the client.
The protocol is defined by the developer when creating the `NetworkingModule` object.

## Usage

```cpp
#include "NetworkingModule.hpp"

int main()
{
    Engine::Network::NetworkingModule network(1234, Engine::Network::NetworkingTypeEnum::UDP, 10);

    std::thread thread(&Engine::Network::NetworkingModule::run(), &network);

    std::vector<Engine::Network::Client> clients = network.getClients();

    std::string message = "Hello World!";

    for (auto client : clients) {
        network.sendMessage(client, message);
    }
    thread.join();
    return 0;
}
```
This code will first create an instance of the `NetworkingModule` class, then it will start a thread that will run the server.
After that, it will get all the clients connected to the server and send them a message.

## Documentation

### NetworkingModule

```cpp
using Engine::Network;

NetworkingModule(int port, NetworkingTypeEnum type, int maxClients);
```
This constructor will create a `NetworkingModule` object with the given port, type and maxClients.

```cpp
void run();
```
This method will start the server.

```cpp
void sendMessage(const std::string &message, const std::size_t &client_id);
```
This method will send a message to the client with matching id.

```cpp
std::vector<Client> getClients();
```
This method will return a vector of all the clients connected to the server.


### Client

```cpp
using Engine::Network;

Client(const std::string &ip, const int &port, const int &socket_fd);
```
This constructor will create a `Client` object with the given ip, port and socket_fd.

```cpp
int getAddress();
```
This method will return the address of the client.

```cpp
std::string getId();
```
This method will return the id of the client.

```cpp
Engine::Network::Buffer &getBuffer();
```
This method will return the buffer of the client.

```cpp
int getSocketFd();
```
This method will return the socket_fd of the client.

```cpp
bool isThreaded();
```
This method will return true if the client is threaded, false otherwise.

```cpp
void setThreaded(bool threaded);
```
This method will set the threaded value of the client.

```cpp
bool isConnected();
```
This method will return true if the client is connected, false otherwise.

```cpp
void setConnected(bool connected);
```
This method will set the connected value of the client.


### Buffer

```cpp
using Engine::Network;

Buffer();
```
This constructor will create a `Buffer` object.

```cpp
void write(const std::string &message);
void write(const char *message, const std::size_t &size);
```
These methods will write a message to the buffer.

```cpp
std::string read();
std::string read(const int &length);
```
These methods will read a message from the buffer.

```cpp
std::string readNextPacket();
```
This method will read the next packet from the buffer.
> A packet is a message that starts with a 1 byte header defined as 0xAA by default and ends with a 1 byte footer defined as 0xBB by default.


### NetworkingTypeEnum

```cpp
using Engine::Network;

enum class NetworkingTypeEnum {
    TCP,
    UDP
};
```
This enum defines the type of the networking module.


### NetworkingExceptions

```cpp
using Engine::Network;

// This exception is thrown when trying to write to a disconnected client.
ClientDisconnectedException();
// This exception is thrown when trying to get a client with an id that is out of range.
ClientIdOutOfRangeException();
// This exception is thrown when the server could not accept a client.
CouldNotAcceptClientException();
// This exception is thrown when the server could not bind the address.
CouldNotBindAddressException();
// This exception is thrown when the server could not receive a message.
CouldNotReceiveException();
// This exception is thrown when the server could not send a message.
CouldNotSendException();
// This exception is thrown when the server could not create a socket.
SocketNotCreatedException();
```

## Authors

Aymeric CHAVEROT
