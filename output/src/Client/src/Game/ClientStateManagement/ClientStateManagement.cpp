#include "../Client.hpp"

void Client::handleExit() {
    _networkingModule = nullptr;
}

void Client::changeState(GameState state) {
    clearCurrentState();
    _gameState = state;
    setupState();
}

void Client::clearCurrentState() {
    _entities.clear();
    for (auto entity : _entities) {
        std::cout << "destruction de l'entitée " << entity << std::endl;
        _gameEngine.getEntityManager()->destroyEntity(entity);
    }
}

void Client::setupState() {
    switch (_gameState) {
        case GameState::MENU:
            setMenu();
            break;
        case GameState::GAME:
            setGame();
            break;
            //        case SETTINGS:
            //            setSettings();
            //            break;
        default:
            break;
    }
}
