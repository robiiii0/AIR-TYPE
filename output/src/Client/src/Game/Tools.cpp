#include "Client.hpp"

void Client::playerInit() {
    player_t player_temp = {-1,
                            {static_cast<bool>(false)},
                            {static_cast<float>(0.0)},
                            {static_cast<float>(0.0)},
                            0};

    for (int i = 0; i < 4; i++) {
        _player.push_back(player_temp);
    }

    for (int i = 0; i < MAX_MISSILES; i++) {
        _missile.push_back(player_temp);
    }
    for (int i = 0; i < MAX_ENEMIES; i++) {
        _enemy.push_back(player_temp);
    }
}

void Client::HandleMovementManager(std::string command) {
    if (command == "exit") {
        _networkingModule->~NetworkingModule();
        _gameEngine.getRendererModule()->getWindow().close();
    } else if (command == "up") {
        std::cout << "Updating player to the up " << _ClientId << std::endl;
        _networkingModule->sendMessage("move up", 0);
    } else if (command == "down") {
        std::cout << "Updating player to the down " << _ClientId << std::endl;
        _networkingModule->sendMessage("move down", 0);
    } else if (command == "left") {
        std::cout << "Updating player to the left " << _ClientId << std::endl;
        _networkingModule->sendMessage("move left", 0);
    } else if (command == "right") {
        std::cout << "Updating player to the right " << _ClientId << std::endl;
        _networkingModule->sendMessage("move right", 0);
    } else if (command == "attack") {
        std::cout << "Updating player to attack " << _ClientId << std::endl;
        _networkingModule->sendMessage("attack", 0);
    }
}
