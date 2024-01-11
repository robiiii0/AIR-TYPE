# R-Type - Game Engine

## Project Documentation

Welcome to the Networking Module of the R-Type project! This section contains comprehensive documentation for the networking-related components.

- **GameEngine**: This directory encompasses the source code and resources related to the game engine of the R-Type project.

- **README.md**: This document provides detailed information about the game engine. It covers the implementation of engine, and game engine's role in the overall architecture.

## Directory Descriptions

- **GameEngine**: Within this directory, you'll find the source code for the game engine. This module is vital for facilitating communication between different components of the R-Type project, such as the client and server.

- **README.md**: This documentation file offers insights into the game engine, serving as a guide for developers working on or exploring the engine aspects of the R-Type project.

## Contribution and Exploration

Feel free to delve into the game engine's source code and contribute to its development or improvement. If you have any questions or suggestions regarding the game engine, please don't hesitate to reach out. Your contributions are invaluable to the success of the R-Type project. Happy coding!

## Get Started

### Prerequisites

No dependencies required.

### Client side

<b>The CLIENT is the part of the project that will be used by the players to play the game. It will be the one that will communicate with the server.</b>

[ENTITY](./EntityManager/README.md) - Read this file containing the documentation for the entity module. It's the module that will be used to manage the entities to display.

[RENDERER](./RendererModule/README.md) - Read this file containing the documentation for the renderer module. It's the module that will be used to display the entities.

[PHYSIC](./PhysicModule/README.md) - Read this file containing the documentation for the physic module. It's the module that will be used to manage the entities' positions.

[HMI](./HmiModule/README.md) - Read this file containing the documentation for the HMI module. It's the module that will be used to detect the user inputs.

[NETWORKING](./NetworkingModule/README.md) - Read this file containing the documentation for the networking module. It's the module that will be used to communicate with the server.

[LOCALSTORAGE](./LocalStorageModule/README.md) - Read this file containing the documentation for the local storage module. It's the module that will be used to store the user preferences.

#### Example

This is a Client class example to display a simple text using the renderer module with SFML:

```cpp
// Client.hpp

#include "../../../GameEngine/GameEngine.hpp"
#include "../../../GameEngine/HmiModule/HmiModule.hpp"
#include "../../../GameEngine/NetworkingModule/NetworkingModule.hpp"
#include "../../../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.hpp"

class Client {
    public:
        Client();
        ~Client();

        void run();

            ...

    private:
        Engine::GameEngine                                  _gameEngine;
        std::vector<std::uint32_t>                          _entities;
        int                                                 _clientId;

        int                                                 _screenWidth;
        int                                                 _screenHeight;

        std::vector<sf::Font>                               _fonts;

        std::unique_ptr<Engine::EntityManager>              _entityManager;
        std::unique_ptr<Engine::HmiModule>                  _hmiModule;
        std::unique_ptr<Engine::Network::NetworkingModule>  _networkingModule;

            ...

};
```

And a constructor example using the renderer module with SFML:

```cpp
// Client.cpp

Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920 ? 1920 : 1920;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080 ? 1080 : 1080;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight,
                                          "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 0;

    LoadFont("src/Client/assets/Fonts/Roboto-bold.ttf");
}
```

This is a simple createText() function using the renderer module with SFML:

```cpp
void createText(
    std::string text, sf::Font &font,
    Engine::Entity::Component::GenericComponents::Vector2f position,
    Engine::Entity::Component::GenericComponents::Vector2f scale,
    sf::Color color, float rotation) {
    // Create an entity.
    uint32_t text_entity = _gameEngine.getEntityManager()->createEntity();

    // Define text data.
    Engine::RendererModule::Components::TextData tmp_text = {text, font, color, position, scale, rotation};

    // Create a text component.
    std::shared_ptr<Engine::RendererModule::Components::TextComponent> textComponent = std::make_shared<Engine::RendererModule::Components::TextComponent>(tmp_text);

    // Add the text component and the entity to the renderer module.
    _gameEngine.getEntityManager()->addComponent(text_entity, textComponent);
    addEntity(text_entity);
}
```

And this is the run() function of the client using the renderer module with SFML to create a text entity, display it and detect user inputs:

```cpp
// Client.cpp

void Client::run() {
    // Create text entity
    createText("Hello World!", _fonts[0], {static_cast<float>(_screenWidth / 2), static_cast<float>(_screenHeight / 2)}, {1, 1}, sf::Color::White, 0);

    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        // Update characteristics of entities
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(), getEntities());

        // Detect user inputs with the HMI module
        std::string eventKey = _hmiModule->keyEvent(_gameEngine.getRendererModule()->UpdateForServer(*_gameEngine.getEntityManager(),getEntities()));

        // Display the entities
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(), getEntities());
    }
}
```

### Server side

The SERVER is the main part of the project. It is the one that will manage the game and the players. It will also be the one that will communicate with the clients.

[NETWORKING](./NetworkingModule/README.md) - Read this file containing the documentation for the networking module. It's the module that will be used to communicate with the clients and the main part of the server.

#### Example

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