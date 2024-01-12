/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    _lastId = 0;
    _scoreId = 0;
    _score = 0;
    _life = 3;
    _tick = 0;

    createSprite({0.0, 0.0}, {2.0, 1.7}, _textures[Textures::BACKGROUND], "");
    createButton(std::bind(&Game::changeGameState, this, GameState::MENU),
                 "Go Menu", _textures[1], _fonts[0],
                 {static_cast<float>(_screenWidth / 1.05),
                  static_cast<float>(_screenHeight / 1.05)},
                 {0.3, 0.3}, sf::Color::White, 0);

    // LIFE
    createSprite({10.0, 10.0}, {0.15, 0.15}, _textures[Textures::LIFE], "");
    _lifeId.push_back(
        *std::max_element(getEntities().begin(), getEntities().end()));
    createSprite({60.0, 10.0}, {0.15, 0.15}, _textures[Textures::LIFE], "");
    _lifeId.push_back(
        *std::max_element(getEntities().begin(), getEntities().end()));
    createSprite({110.0, 10.0}, {0.15, 0.15}, _textures[Textures::LIFE], "");
    _lifeId.push_back(
        *std::max_element(getEntities().begin(), getEntities().end()));

    // SCORE
    createText("Score : " + std::to_string(_score), _fonts[0], {70.0, 70.0},
               {1, 1}, sf::Color::White, 0);
    _scoreId = *std::max_element(getEntities().begin(), getEntities().end());
}

void Game::gameLoop() {
    if (_gameState == GameState::GAME &&
        (_lastId !=
             *std::max_element(getEntities().begin(), getEntities().end()) ||
         _lastId == 0) &&
        _tick == 0) {
        std::cout << "BEFORE CREATE: " << _lastId << " "
                  << *std::max_element(getEntities().begin(),
                                       getEntities().end())
                  << std::endl;
        _lastId =
            *std::max_element(getEntities().begin(), getEntities().end()) + 1;

        std::cout << "CREATE: " << _lastId << " "
                  << *std::max_element(getEntities().begin(),
                                       getEntities().end())
                  << std::endl;

        createButton(
            [this]() {
                _sounds[1]->play();
                removeEntity(_lastId);
                updateScore();
                _tick = 0;
            },
            "", _textures[Textures::PLAYER], _fonts[0],
            {randomFloat(25.0, 1175.0), randomFloat(25.0, 695.0)}, {0.3, 0.3},
            sf::Color::White, 0);
    } else if (_gameState == GameState::GAME && _tick == 100) {
        if (_tick == 100) {
            _life--;
            _tick = 0;
            std::cout << "BEFORE REMOVE -> LastId: " << _lastId << " Max: "
                      << *std::max_element(getEntities().begin(),
                                           getEntities().end())
                      << std::endl;
            removeEntity(_lastId);
        }
    } else
        _tick++;

    // std::cout << "CONDITION: " << _lastId << " " <<
    // *std::max_element(getEntities().begin(), getEntities().end()) <<
    // std::endl;
}

void Game::updateScore() {
    removeEntity(_scoreId);
    _score++;
    createText("Score : " + std::to_string(_score), _fonts[0], {70.0, 70.0},
               {1, 1}, sf::Color::White, 0);
    _scoreId = *std::max_element(getEntities().begin(), getEntities().end());
}

void Game::checkLife() {
    if (_life < _lifeId.size()) {
        removeEntity(_lifeId[_life]);
        _lifeId.erase(_lifeId.begin() + _life);
    }
    if (_life == 0 && _gameState == GameState::GAME)
        changeGameState(GameState::GAMEOVER);
}
