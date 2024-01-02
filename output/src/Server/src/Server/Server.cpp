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
        _globalMessages.emplace("New Player");
    }
    for (auto &client : _networkingModule->getClients()) {  // ? client update
        if (client.getBuffer()->hasPacket()) {
            std::cout << "Client " << client.getId()
                      << " sent: " << client.getBuffer()->read()
                      << std::endl;  // TODO: handle packet
        }
    }
    while (!_globalMessages.empty()) {  // ? global messages
        std::cout << "Global message: " << _globalMessages.front() << std::endl;
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
