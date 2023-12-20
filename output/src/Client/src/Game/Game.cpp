//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _gameEngine.getRendererModule()->init(
        int(sf::VideoMode::getDesktopMode().width),
        int(sf::VideoMode::getDesktopMode().height), "Air-Type", 60);
}

void Game::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update();
        _gameEngine.getRendererModule()->handleEvent(*_gameEngine.getEntityManager(), _gameEngine.getEntityManager()->getNbEntites());
        _gameEngine.getRendererModule()->render(
            *_gameEngine.getEntityManager(),
            _gameEngine.getEntityManager()->getNbEntites());
    }
}

Engine::GameEngine &Game::getGameEngine() { return _gameEngine; }

// void Game::changeState() {
//
// }
