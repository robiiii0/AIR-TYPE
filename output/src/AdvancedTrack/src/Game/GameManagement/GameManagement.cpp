/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    _score = 0;
    uint32_t scoreId = 0;

    createSprite({0.0, 0.0}, {2.0, 1.7}, _textures[Textures::BACKGROUND], "");
    createButton(std::bind(&Game::changeGameState, this, GameState::MENU),
                 "Go Menu", _textures[1], _fonts[0],
                 {static_cast<float>(_screenWidth / 1.05),
                  static_cast<float>(_screenHeight / 1.05)},
                 {0.3, 0.3}, sf::Color::White, 0);
    createText("Score : " + std::to_string(_score), _fonts[0], {100, 100},
               {1, 1}, sf::Color::White, 0);
    scoreId = *std::max_element(getEntities().begin(), getEntities().end());

    _lastId = *std::max_element(getEntities().begin(), getEntities().end()) + 1;
    createButton([this]() { removeEntity(_lastId); }, "",
                 _textures[Textures::PLAYER], _fonts[0],
                 {randomFloat(0.0, 1200.0), randomFloat(0.0, 720.0)},
                 {0.3, 0.3}, sf::Color::White, 0);
}

void Game::gameLoop() {
    if (_gameState == GameState::GAME &&
        _lastId >
            *std::max_element(getEntities().begin(), getEntities().end())) {
        _lastId++;
        createButton([this]() { removeEntity(_lastId); }, "",
                     _textures[Textures::PLAYER], _fonts[0],
                     {randomFloat(0.0, 1200.0), randomFloat(0.0, 720.0)},
                     {0.3, 0.3}, sf::Color::White, 0);
    }
}
