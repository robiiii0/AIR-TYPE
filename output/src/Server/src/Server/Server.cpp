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
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        4242, Engine::Network::NetworkingTypeEnum::UDP, 10);
    _nb_clients = 0;
}

void Server::loop() {
    std::cout << "loop" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    networkLoop();
}

void Server::stop() { _running = false; }

void Server::networkLoop() {
    if (_networkingModule->getClients().size() > _nb_clients) {  // ? new client
        std::cout << "New Client connected" << std::endl;
        auto &client = _networkingModule->getClients().back();
        std::cout << "Welcoming Client " << client.getId() << std::endl;
        _networkingModule->sendMessage(
            "Hello", client.getId());  // TODO: send real welcome message
        _nb_clients = _networkingModule->getClients().size();
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client update
        if (client.getBuffer()->hasPacket()) {
            std::cout << "Client " << client.getId()
                      << " sent: " << client.getBuffer()->read()
                      << std::endl;  // TODO: handle packet
        }
    }
    std::cout << "networkLoop" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
