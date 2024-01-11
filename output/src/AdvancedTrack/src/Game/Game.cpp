/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _gameEngine() {
    _screenWidth = 1280;
    _screenHeight = 720;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight,
                                          "PokeHunter", 60);

    _score = 0;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _gameState = GameState::MENU;

    LoadFont("assets/Fonts/Roboto-Bold.ttf");
    LoadTexture("assets/Sprite/background.jpg");
    LoadTexture("assets/Sprite/pokeball.png");
}

void Game::run() {
    setUpState();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        std::string eventKey = _hmiModule->keyEvent(
            _gameEngine.getRendererModule()->HandleEvent(
                *_gameEngine.getEntityManager(), getEntities()));

        _gameEngine.getPhysicModule()->update(*_gameEngine.getEntityManager(),
                                              getEntities(), 0.5);
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
}

void Game::handleExit() { _gameState = GameState::EXIT; }
