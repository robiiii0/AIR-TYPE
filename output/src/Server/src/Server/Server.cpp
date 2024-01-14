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
    _ennemy_spawn_clock = std::chrono::high_resolution_clock::now();
    _update_time = std::chrono::high_resolution_clock::now();
    srand(time(NULL));
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
    update();
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
        // std::cout << "Server Tickrate: " << color << tickrate << color_end
        //           << " / " << SERVER_TICKRATE << std::endl;
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
                                  " " +
                                  std::to_string(position->getValue().x + 2) +
                                  " " + std::to_string(position->getValue().y);
                _clientMessages[id].emplace(msg);
            }
        }
    }
    // _clientMessages[id].emplace("STATUS END");
}

void Server::createPlayer(std::uint32_t id) {
    _playerEntities[id] = _gameEngine->getEntityManager()->createEntity();
    Engine::Entity::Component::GenericComponents::Vector2f position_data{
        500.0, static_cast<float>(700.0 + (50 * id))};
    auto position = std::make_shared<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>(
        position_data);
    _gameEngine->getEntityManager()->addComponent(_playerEntities[id],
                                                  position);
    std::string msg =
        "add player " + std::to_string(id) + " " +
        std::to_string(position->getValue().x + (100 * _nb_clients)) + " " +
        std::to_string(position->getValue().y);

    std::vector<std::string> message;

    message.push_back(msg);
    sendToAllExcept(
        id, _networkingModule->getSerializer().serializeToPacket(message));
    sendGameStatus(id);
}

void Server::createEnnemy(std::uint32_t id) {
    float randomFloat = static_cast<float>(rand() % 800 + 1);

    _ennemyEntities[id] = _gameEngine->getEntityManager()->createEntity();
    Engine::Entity::Component::GenericComponents::Vector2f position_data{
        1800.0, randomFloat};

    auto position = std::make_shared<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>(
        position_data);
    _gameEngine->getEntityManager()->addComponent(_ennemyEntities[id],
                                                  position);
    std::string msg =
        "add ennemy " + std::to_string(id) + " " +
        std::to_string(position->getValue().x + (100 * _nb_clients)) + " " +
        std::to_string(position->getValue().y);

    std::vector<std::string> message;

    message.push_back(msg);
    sendToAllExcept(
        id, _networkingModule->getSerializer().serializeToPacket(message));
    sendGameStatus(id);
}

void Server::createMissile(std::uint32_t id) {
    _missileEntities[_missileID] =
        _gameEngine->getEntityManager()->createEntity();
    _missileID++;

    uint32_t entity_id = _playerEntities[id];
    auto     components =
        _gameEngine->getEntityManager()->getEntity(entity_id)->_components;
    for (auto component : components) {
        if (typeid(*component) ==
            typeid(Engine::Entity::Component::GenericComponents::
                       Vector2fComponent)) {
            auto position = std::dynamic_pointer_cast<
                Engine::Entity::Component::GenericComponents::
                    Vector2fComponent>(component);
            Engine::Entity::Component::GenericComponents::Vector2f
                 position_data = {position->getValue().x + 25,
                                  position->getValue().y + 10};
            auto position_missile =
                std::make_shared<Engine::Entity::Component::GenericComponents::
                                     Vector2fComponent>(position_data);
            _gameEngine->getEntityManager()->addComponent(_missileEntities[id],
                                                          position_missile);
            std::string msg = "add missile " + std::to_string(id) + " " +
                              std::to_string(position_data.x) + " " +
                              std::to_string(position_data.y);
            std::cout << msg << std::endl;
            _globalMessages.emplace(msg);
        }
    }
}

void Server::movePlayer(int type, std::uint32_t id) {
    if (type == 1) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(_playerEntities[id])
                              ->_components;
        for (auto &component2 : components) {
            if (auto posComp = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component2)) {
                Engine::Entity::Component::GenericComponents::Vector2f
                    NewPosition = {{posComp->getValue().x},
                                   {posComp->getValue().y + float(-10.0)}};
                posComp->setValue(NewPosition);
            }
        }
    }
    if (type == 2) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(_playerEntities[id])
                              ->_components;
        for (auto &component2 : components) {
            if (auto posComp = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component2)) {
                Engine::Entity::Component::GenericComponents::Vector2f
                    NewPosition = {{posComp->getValue().x},
                                   {posComp->getValue().y + float(10.0)}};
                posComp->setValue(NewPosition);
            }
        }
    }
    if (type == 3) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(_playerEntities[id])
                              ->_components;
        for (auto &component2 : components) {
            if (auto posComp = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component2)) {
                Engine::Entity::Component::GenericComponents::Vector2f
                    NewPosition = {{posComp->getValue().x + float(10.0)},
                                   {posComp->getValue().y}};
                posComp->setValue(NewPosition);
            }
        }
    }
    if (type == 4) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(_playerEntities[id])
                              ->_components;
        for (auto &component2 : components) {
            if (auto posComp = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component2)) {
                Engine::Entity::Component::GenericComponents::Vector2f
                    NewPosition = {{posComp->getValue().x + float(-10.0)},
                                   {posComp->getValue().y}};
                posComp->setValue(NewPosition);
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
        _networkingModule->sendMessage(
            "Welcome client " + std::to_string(client.getId()), client.getId());
        _nb_clients = _networkingModule->getClients().size();
        createPlayer(client.getId());
        // for (int i = 0; i < 5; i++)
        // createEnemy(i);
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client update
        while (client.getBuffer()->hasPacket()) {
            std::string packet = client.getBuffer()->readNextPacket();
            std::cout << "Client " << client.getId() << " sent: " << packet
                      << std::endl;  // TODO: handle packet

            if (packet == "attack") {
                createMissile(0);
            }

            if (packet.find("move") != std::string::npos) {
                if (packet.find("up") != std::string::npos) {
                    movePlayer(1, client.getId());
                }
                if (packet.find("down") != std::string::npos) {
                    movePlayer(2, client.getId());
                }
                if (packet.find("right") != std::string::npos) {
                    movePlayer(3, client.getId());
                }
                if (packet.find("left") != std::string::npos) {
                    movePlayer(4, client.getId());
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
            // for (int i = 0; i < msg_client.size(); i++) {
            //     _networkingModule->sendMessage(msg_client[i],
            //     client.getId());
            // }
            _networkingModule->sendMessage(
                _networkingModule->getSerializer().serializeToPacket(messages),
                client.getId());
    }
}

void Server::updatePlayer() {
    for (auto &player : _playerEntities) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(player.second)
                              ->_components;
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);
                std::string msg = "add player " +
                                  std::to_string(player.second) + " " +
                                  std::to_string(position->getValue().x) + " " +
                                  std::to_string(position->getValue().y);
                _globalMessages.emplace(msg);
            }
        }
    }
}

void Server::updateEnnemies() {
    // TODO : update ennemy
    // mettre a jour la position du player
    // faire le message (add ennemy id x y)
    // bien le mettre dans _globalMessages

    for (auto &ennemy : _ennemyEntities) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(ennemy.second)
                              ->_components;
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);
                auto new_position = position->getValue();
                new_position.x -= 0.02;
                position->setValue(new_position);
                std::string msg = "add ennemy " +
                                  std::to_string(ennemy.second) + " " +
                                  std::to_string(position->getValue().x) + " " +
                                  std::to_string(position->getValue().y);
                _globalMessages.emplace(msg);
            }
        }
    }
}

void Server::updateMissile() {
    for (auto &missile : _missileEntities) {
        auto components = _gameEngine->getEntityManager()
                              ->getEntity(missile.second)
                              ->_components;
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::Entity::Component::GenericComponents::
                           Vector2fComponent)) {
                auto position = std::dynamic_pointer_cast<
                    Engine::Entity::Component::GenericComponents::
                        Vector2fComponent>(component);
                auto new_position = position->getValue();
                std::cout << "ya r l'ekip" << std::endl;
                new_position.x += 0.02;
                position->setValue(new_position);
                std::string msg = "add missile " +
                                  std::to_string(missile.second) + " " +
                                  std::to_string(position->getValue().x) + " " +
                                  std::to_string(position->getValue().y);
                _globalMessages.emplace(msg);
            }
        }
    }
}

void Server::update() {
    // ? update all entities
    updatePlayer();
    // if (_update_time + std::chrono::microseconds(750) <
    //     std::chrono::high_resolution_clock::now()) {
    //     _update_time = std::chrono::high_resolution_clock::now();
    updateEnnemies();
    updateMissile();
    // }
    if (_ennemy_spawn_clock + std::chrono::seconds(8) <
        std::chrono::high_resolution_clock::now()) {
        _ennemy_spawn_clock = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 5; i++) {
            createEnnemy(i);
        }
    }
    // ? update all components
    // ? update all systems
}
