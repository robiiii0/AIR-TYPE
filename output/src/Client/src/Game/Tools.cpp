#include "Client.hpp"

void Client::playerInit() {
    Engine::Network::Serializer::entity_t entityTemp = {
        -1,
        {static_cast<bool>(false)},
        {static_cast<float>(0.0)},
        {static_cast<float>(0.0)}};
    for (int i = 0; i < 4; i++) {
        _player.push_back(entityTemp);
    }
}

void Client::HandleMovementManager(std::string command) {
    if (command == "exit") {
        _networkingModule->~NetworkingModule();
        _gameEngine.getRendererModule()->getWindow().close();
    } else if (command == "up") {
        std::cout << "Updating player position" << std::endl;
        _networkingModule->sendMessage("move up", _ClientId);
    } else if (command == "down") {
        std::cout << "Updating player position" << std::endl;
                _networkingModule->sendMessage("move down", _ClientId);
    } else if (command == "left") {
        std::cout << "Updating player position" << std::endl;
                _networkingModule->sendMessage("move left", _ClientId);
    } else if (command == "right") {
        std::cout << "Updating player position" << std::endl;
        _networkingModule->sendMessage("move right", _ClientId);
    }
}
