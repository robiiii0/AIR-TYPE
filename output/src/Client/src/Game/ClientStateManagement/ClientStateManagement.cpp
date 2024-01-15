#include "../Client.hpp"

void Client::handleExit() {
    // TODO: stop the networking module before destroying it.
    _networkingModule = nullptr;
    std::cout << "networking module destroyed" << std::endl;
    for (auto &sound : _sounds) {
        sound->stop();
        sound = nullptr;
        std::cout << "sound stopped" << std::endl;
    }
    _sounds.clear();
    _gameEngine.getRendererModule()->getWindow().close();
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
        case GameState::SETTINGS:
            setSettings();
            break;
        case GameState::KEYBINDING:
            ChangeKeyBinding();
        case GameState::WIN:
            winMenu();
            break;
        case GameState::GAMEOVER:
            loseMenu();
            break;
        default:
            break;
    }
}
