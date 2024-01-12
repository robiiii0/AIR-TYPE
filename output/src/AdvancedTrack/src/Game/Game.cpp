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
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _gameState = GameState::MENU;
    _score = 0;

    LoadSound("assets/Sounds/pokemon-music.wav", true, true, 20.0);
    LoadSound("assets/Sounds/click.wav", false, false, 50.0);
    LoadFont("assets/Fonts/Roboto-Bold.ttf");
    LoadTexture("assets/Sprite/background.jpg");
    LoadTexture("assets/Sprite/pokeball.png");
    LoadTexture("assets/Sprite/heart.png");
}

void Game::run() {
    setUpState();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        std::string eventKey =
            _hmiModule->keyEvent(_gameEngine.getRendererModule()->HandleEvent(
                *_gameEngine.getEntityManager(), getEntities()));

        // Game functionnal functions.
        gameLoop();
        checkLife();

        _gameEngine.getPhysicModule()->update(*_gameEngine.getEntityManager(),
                                              getEntities(), 0.5);
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
}

float Game::randomFloat(float min, float max) {
    std::random_device               rd;
    std::mt19937                     gen(rd());
    std::uniform_real_distribution<> distr(min, max);
    return distr(gen);
}

void Game::handleExit() { _gameState = GameState::EXIT; }
