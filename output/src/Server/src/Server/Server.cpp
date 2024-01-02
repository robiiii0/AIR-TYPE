/*
** EPITECH PROJECT, 2023
** output
** File description:
** Server
*/

#include "Server.hpp"

Server::Server() { init(); }

Server::~Server() {}

int Server::run() {
    _running = true;
    while (_running) {
        loop();
    }
    return 0;
}

void Server::init() {
    _running = false;
    _networkingModule = std::make_unique<Engine::Network::NetworkingModule>(
        4242, Engine::Network::NetworkingTypeEnum::UDP, 10);
    _nb_clients = 0;
    _gameEngine = std::make_unique<Engine::GameEngine>(false);
}

void Server::loop() {
    _clock = std::chrono::high_resolution_clock::now();
    networkLoop();
    applyTickrate();
}

void Server::stop() { _running = false; }

void Server::applyTickrate() {
    const auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now() - _clock);
    if (elapsed.count() < 1000 / SERVER_TICKRATE) {
        const long duration = 1000000 / SERVER_TICKRATE;
        const long sleepTime = duration - elapsed.count();
        if (sleepTime > 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(sleepTime));
        }
        std::cout << "Server Tickrate: "
                  << 1.0 /
                         std::chrono::duration_cast<std::chrono::microseconds>(
                             std::chrono::high_resolution_clock::now() - _clock)
                             .count() *
                         1000000
                  << std::endl;
    }
}

void Server::sendToAllExcept(std::uint32_t id, std::string message) {
    for (auto &client : _networkingModule->getClients()) {
        if (client.getId() != id) {
            _clientMessages[client.getId()].emplace(message);
        }
    }
}

void Server::sendGameStatus(std::uint32_t id) {
    // ? send all players
    _clientMessages[id].emplace("STATUS START");
    for (auto &entity : _playerEntities) {
        auto player = _gameEngine->getEntityManager()->getEntity(entity.second);
        for (auto &component : player->_components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);
                std::string msg = "Player " + std::to_string(entity.first) +
                                  " " + std::to_string(position->getValue().x) +
                                  " " + std::to_string(position->getValue().y);
                _clientMessages[id].emplace(msg);
            }
        }
        // std::string msg = "Player " + std::to_string(entity.first) + " " +
        //                   std::to_string(position->getValue().x) + " " +
        //                   std::to_string(position->getValue().y);
        // _clientMessages[id].emplace(msg);
    }
    _clientMessages[id].emplace("STATUS END");
}

void Server::createPlayer(std::uint32_t id) {
    std::cout << "Creating player " << id << std::endl;
    _playerEntities[id] = _gameEngine->getEntityManager()->createEntity();
    Engine::Entity::Component::GenericComponents::Vector2f position_data{500.0,
                                                                         static_cast<float>(700.0 + (50 * id)) };
    auto position = std::make_shared<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>(
        position_data);
    _gameEngine->getEntityManager()->addComponent(_playerEntities[id],
                                                  position);
    std::string msg = "New Player " + std::to_string(id) + " " +
                      std::to_string(position->getValue().x) + " " +
                      std::to_string(position->getValue().y);

    sendToAllExcept(id, msg);
    sendGameStatus(id);
}

void Server::networkLoop() {
    std::cout << "nb clients: " << _networkingModule->getClients().size()
              << std::endl;
    if (_networkingModule->getClients().size() > _nb_clients) {  // ? new client
        std::cout << "New Client connected" << std::endl;
        auto &client = _networkingModule->getClients().back();
        std::cout << "Welcoming Client " << client.getId() << std::endl;
        _clientMessages[client.getId()] = std::queue<std::string>();
        _clientMessages[client.getId()].emplace(
            "Welcome");  // TODO: send a real welcome msg
        _nb_clients = _networkingModule->getClients().size();
        createPlayer(client.getId());
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client update
        while (client.getBuffer()->hasPacket()) {
            std::string packet = client.getBuffer()->readNextPacket();
            std::cout << "Client " << client.getId() << " sent: " << packet
                      << std::endl;  // TODO: handle packet
            
        }
    }
    while (!_globalMessages.empty()) {  // ? global messages
        std::cout << "Broadcasting: " << _globalMessages.front() << std::endl;
        _networkingModule->broadcastMessage(_globalMessages.front());
        _globalMessages.pop();
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client messages
        while (!_clientMessages[client.getId()].empty()) {
            std::cout << "Client " << client.getId()
                      << " message: " << _clientMessages[client.getId()].front()
                      << std::endl;
            _networkingModule->sendMessage(
                _clientMessages[client.getId()].front(), client.getId());
            _clientMessages[client.getId()].pop();
        }
    }
}
