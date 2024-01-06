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
    _missileID = 0;
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
        // _globalMessages.emplace("add player 0 10 10");
        // _globalMessages.emplace("add player 0 10 10");
        // _globalMessages.emplace("add player 0 10 10");

        auto tickrate = 1.0 /
                        std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now() - _clock)
                            .count() *
                        1000000;
        std::string color = "\033[1;32m";
        if (tickrate / SERVER_TICKRATE < 0.9) color = "\033[1;33m";
        if (tickrate / SERVER_TICKRATE < 0.8) color = "\033[1;31m";
        std::string color_end = "\033[0m";
        std::cout << "Server Tickrate: " << color << tickrate << color_end
                  << " / " << SERVER_TICKRATE << std::endl;
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
    // _clientMessages[id].emplace("STATUS START");
    for (auto &entity : _playerEntities) {
        auto player = _gameEngine->getEntityManager()->getEntity(entity.second);
        for (auto &component : player->_components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);
                std::string msg = "add player " + std::to_string(entity.first) +
                                  " " + std::to_string(position->getValue().x) +
                                  " " + std::to_string(position->getValue().y);
                _clientMessages[id].emplace(msg);
            }
        }
    }
    // _clientMessages[id].emplace("STATUS END");
}

void Server::createPlayer(std::uint32_t id) {
    std::cout << "Creating player " << id << std::endl;
    _playerEntities[id] = _gameEngine->getEntityManager()->createEntity();
    Engine::Entity::Component::GenericComponents::Vector2f position_data{
        500.0, static_cast<float>(700.0 + (50 * id))};
    auto position = std::make_shared<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>(
        position_data);
    _gameEngine->getEntityManager()->addComponent(_playerEntities[id],
                                                  position);
    std::string msg = "add player " + std::to_string(id) + " " +
                      std::to_string(position->getValue().x) + " " +
                      std::to_string(position->getValue().y);

    std::vector<std::string> message;
    // std::string msg_to_send = "add player " + std::to_string(_nb_clients) + " 10 " + std::to_string(10 + (5  * _nb_clients));
    // _globalMessages.emplace(msg_to_send);
    message.push_back(msg);
    sendToAllExcept(
        id, _networkingModule->getSerializer().serializeToPacket(message));
    sendGameStatus(id);
}

void Server::createMissile(std::uint32_t id) {
    std::cout << "Creating missile " << id << std::endl;
    _missileEntities[id] = _gameEngine->getEntityManager()->createEntity();
    std::cout << "Missile " << id << " created" << std::endl;

    for (auto &entity : _playerEntities) {
        auto player = _gameEngine->getEntityManager()->getEntity(entity.second);
        for (auto &component : player->_components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);

                Engine::Entity::Component::GenericComponents::Vector2f
                    position_data(position->getValue());
                _gameEngine->getEntityManager()->addComponent(
                    _missileEntities[id], position);
                std::string msg = "add missile " + std::to_string(id) + " " +
                                  std::to_string(position->getValue().x) + " " +
                                  std::to_string(position->getValue().y);
                std::cout << msg << std::endl;
                _globalMessages.emplace(msg);
            }
        }
    }
}

void Server::networkLoop() {
    if (_networkingModule->getClients().size() > _nb_clients) {  // ? new client
        std::cout << "New Client connected" << std::endl;
        auto &client = _networkingModule->getClients().back();
        std::cout << "Welcoming Client " << client.getId() << std::endl;
        _clientMessages[client.getId()] = std::queue<std::string>();
        _nb_clients = _networkingModule->getClients().size();
        createPlayer(client.getId());
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client update
        while (client.getBuffer()->hasPacket()) {
            std::string packet = client.getBuffer()->readNextPacket();
            std::cout << "Client " << client.getId() << " sent: " << packet
                      << std::endl;  // TODO: handle packet

            if (packet == "ATTACK") {
                std::cout << "Creating missile" << std::endl;
                createMissile(_missileID);
                _missileID++;
            }

            if (packet.find("Move") != std::string::npos) {
                if (packet.find("up") != std::string::npos) {
                    // movePlayer
                }
            }
        }
    }
    std::vector<std::string> messages;
    while (!_globalMessages.empty()) {  // ? global messages
        while (_globalMessages.size() > 0) {
            messages.push_back(_globalMessages.front());
            _globalMessages.pop();
        }
        // _networkingModule->broadcastMessage(
            // _networkingModule->getSerializer().serializeToPacket(messages));
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client messages
        std::vector<std::string> msg_client;
        for (auto &msg : messages) {
            msg_client.push_back(msg);
        }
        while (!_clientMessages[client.getId()].empty()) {
            std::cout << "Client " << client.getId()
                      << " message: " << _clientMessages[client.getId()].front()
                      << std::endl;
            msg_client.push_back(_clientMessages[client.getId()].front());
            // _networkingModule->sendMessage(
                // _clientMessages[client.getId()].front(), client.getId());
            _clientMessages[client.getId()].pop();
        }
        if (messages.size() > 0)
            _networkingModule->sendMessage(
                _networkingModule->getSerializer().serializeToPacket(msg_client),
                client.getId());
        // _networkingModule->sendMessage(
        //     _networkingModule->getSerializer().serializeToPacket(messages), client.getId());
    }
}

void Server::updatePlayer(std::uint32_t id) {
    // TODO : update player
    // mettre a jour la position du player
    // faire le message (add player id x y)
    // bien le mettre dans _globalMessages

    for (auto &player : _playerEntities) {
        auto components = _gameEngine->getEntityManager()->getEntity(player.second)->_components;
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);
                std::string msg = "add player " + std::to_string(id) + " " +
                                  std::to_string(position->getValue().x) + " " +
                                  std::to_string(position->getValue().y);
                _clientMessages[id].emplace(msg);
            }
        }
    }
}

void Server::update()
{
    
    // updatePlayer(0);
}
