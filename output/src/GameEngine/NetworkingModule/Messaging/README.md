# Messager - Networking Messager

## Overview

The `Messager` class is a component within the R-Type project designed to facilitate communication between clients using various networking protocols. This class encapsulates functionalities for sending and receiving messages between clients and handling exceptions related to networking operations.

## Structure Explanation

### `Messager` Class

```cpp
class Messager {
public:
    // Constructor for initializing the Messager with a specified networking type.
    Messager(NetworkingTypeEnum type);
    
    // Destructor for cleanup.
    ~Messager();

    // Method to send a message to a client.
    void sendMessage(const std::string &message,
                     Engine::Network::Client &client,
                     int socket_fd);

    // Method to start receiving messages from a client.
    void startReceiving(Engine::Network::Client &client);

protected:
private:
    // Method representing the loop for receiving messages.
    void receiveLoop(Engine::Network::Client &client);

    // Mutex and condition variable for synchronization.
    std::mutex mutex;
    std::condition_variable cv;

    // Variable indicating the mode of the Messager.
    bool _mode;
};
```

#### Public Methods

- **Constructor (`Messager(NetworkingTypeEnum type)`) and Destructor (`~Messager()`)**
  - The constructor initializes the `Messager` with a specified networking type, indicating whether the messager operates over TCP or UDP.
  - The destructor is responsible for any necessary cleanup when the `Messager` is no longer needed.

- **`void sendMessage(const std::string &message, Engine::Network::Client &client, int socket_fd)`**
  - Method to send a message to a specified client using the provided socket file descriptor.

- **`void startReceiving(Engine::Network::Client &client)`**
  - Method to start receiving messages from a specified client. This method initiates a separate thread to handle the receive loop.

#### Private Methods

- **`void receiveLoop(Engine::Network::Client &client)`**
  - Method representing the loop for receiving messages. This function runs in a separate thread and continuously receives messages from the specified client.

- **Synchronization Variables (`std::mutex mutex`, `std::condition_variable cv`):**
  - These variables are used for synchronization between threads to ensure safe concurrent operations.

- **Mode Indicator (`bool _mode`):**
  - A variable indicating the mode of the `Messager`. The specific use of this variable is not detailed in the provided code snippet.

#### Usage Example

```cpp
// Example usage of Messager
Engine::Network::Messager messager(NetworkingTypeEnum::TCP);

// Sending a message
messager.sendMessage("Hello, R-Type!", client, socket_fd);

// Starting the receiving loop
messager.startReceiving(client);
```

In this example, a `Messager` instance is created with a specified networking type. A message is sent to a client using the `sendMessage` method, and the receiving loop is initiated with `startReceiving`. Developers can customize the usage according to the networking requirements of the R-Type project.

This `Messager` class plays a crucial role in handling communication between clients, providing a convenient interface for sending and receiving messages while handling exceptions related to networking operations.