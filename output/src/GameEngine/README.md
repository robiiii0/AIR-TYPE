# R-Type - Networking Module

## Project Documentation

Welcome to the Networking Module of the R-Type project! This section contains comprehensive documentation for the networking-related components.

- **NetworkingModule**: This directory encompasses the source code and resources related to the networking module of the R-Type project.

- **README.md**: This document provides detailed information about the networking module. It covers the implementation of networking, the protocols used, and the networking module's role in the overall architecture.

## Directory Descriptions

- **NetworkingModule**: Within this directory, you'll find the source code for the networking module. This module is vital for facilitating communication between different components of the R-Type project, such as the client and server.

- **README.md**: This documentation file offers insights into the networking module, serving as a guide for developers working on or exploring the networking aspects of the R-Type project.

## Contribution and Exploration

Feel free to delve into the networking module's source code and contribute to its development or improvement. If you have any questions or suggestions regarding the networking module, please don't hesitate to reach out. Your contributions are invaluable to the success of the R-Type project. Happy coding!


## Get Started

### Prerequisites

- [CMake](https://cmake.org/download/) (version >= 3.17)
- [Conan](https://docs.conan.io/en/latest/installation.html)

### Client side

<b>The client is the part of the project that will be used by the players to play the game. It will be the one that will communicate with the server.</b>


[ENTITY](./EntityManager/README.md) - Read this file containing the documentation for the entity module. It's the module that will be used to manage the entities to display.

[RENDERER](./RendererModule/README.md) - Read this file containing the documentation for the renderer module. It's the module that will be used to display the entities.

[PHYSIC](./PhysicModule/README.md) - Read this file containing the documentation for the physic module. It's the module that will be used to manage the entities' positions.

[HMI](./HmiModule/README.md) - Read this file containing the documentation for the HMI module. It's the module that will be used to detect the user inputs.

[NETWORKING](./NetworkingModule/README.md) - Read this file containing the documentation for the networking module. It's the module that will be used to communicate with the server.

[LOCALSTORAGE](./LocalStorageModule/README.md) - Read this file containing the documentation for the local storage module. It's the module that will be used to store the user preferences.


### Server side

The server is the main part of the project. It is the one that will manage the game and the players. It will also be the one that will communicate with the clients.

[NETWORKING](./NetworkingModule/README.md) - Read this file containing the documentation for the networking module. It's the module that will be used to communicate with the clients and the main part of the server.

This is a Server class example using the networking module:

```cpp
// Server.hpp

#include "../../../GameEngine/GameEngine.hpp"
#include "../../../GameEngine/NetworkingModule/NetworkingModule.hpp"

class Server {
    public:
        Server();
        ~Server();

            ...

    private:
        std::unique_ptr<Engine::Network::NetworkingModule> _networkingModule;
        std::unique_ptr<Engine::GameEngine>                _gameEngine;

            ...

};
```

In your constructor, you can create a new instance of the networking module using UDP like this:

``` cpp
// Server.cpp

Server::Server() {
    _networkingModule = std::make_unique<Engine::Network::NetworkingModule>(
        4242, Engine::Network::NetworkingTypeEnum::UDP, 10);
    _gameEngine = std::make_unique<Engine::GameEngine>(false);

        ...

}
```

And then you can use the networking module following this [README](./NetworkingModule/README.md).