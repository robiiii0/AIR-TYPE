//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _gameEngine.getRendererModule()->init(1920, 1080, "Air-Type", 60);
}

void Game::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update();
        _gameEngine.getRendererModule()->render();
    }
}

Engine::GameEngine &Game::getGameEngine() {
    return _gameEngine;
}
// void Game::changeState() {
//
// }
