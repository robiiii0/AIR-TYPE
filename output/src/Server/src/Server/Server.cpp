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
    _networkingModule->run();
    while (_running) {
        loop();
    }
    return 0;
}

void Server::init() {
    _running = false;
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        4242, Engine::Network::NetworkingTypeEnum::UDP, 10);
}

void Server::loop() {
    std::cout << "loop" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Server::stop() { _running = false; }
