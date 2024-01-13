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

//    ------------------------------------------------------------
    uint32_t id_celebi =
        *std::max_element(getEntities().begin(), getEntities().end()) + 1;
    createButton(
        [this, id_celebi]() {
            createSprite({static_cast<float>(-20),
                          static_cast<float>(_screenHeight - 150)},
                         {0.2, 0.2}, _textures[CAPTURE], "");
            createSprite({static_cast<float>(40),
                          static_cast<float>(_screenHeight - 130)},
                         {0.07, 0.07}, _textures[CELEBI], "");
            createText("Celebi captured !", _fonts[0],
                       {static_cast<float>(120),
                        static_cast<float>(_screenHeight - 130)},
                       {1, 1}, sf::Color::White, 0);
            _captured = true;
            removeEntity(id_celebi);
        },
        "", _textures[CELEBI], _fonts[0],
        {static_cast<float>(_screenWidth - 200), static_cast<float>(50)},
        {0.05, 0.05}, sf::Color::White, 0);

//    ------------------------------------------------------------

    // LIFE
    createSprite({10.0, 10.0}, {0.15, 0.15}, _textures[Textures::LIFE], "");
    _lifeId.push_back(getLastId());
    createSprite({60.0, 10.0}, {0.15, 0.15}, _textures[Textures::LIFE], "");
    _lifeId.push_back(getLastId());
    createSprite({110.0, 10.0}, {0.15, 0.15}, _textures[Textures::LIFE], "");
    _lifeId.push_back(getLastId());

    // SCORE
    createText("Score : " + std::to_string(_score), _fonts[0], {70.0, 70.0},
               {1, 1}, sf::Color::White, 0);
    _scoreId = getLastId();
}

void Game::gameLoop() {
    // Pokeball creation.
    if (_gameState == GameState::GAME && !_pokeball && _tick == 0) {
        createButton(
            [this]() {
                _sounds[1]->play();
                removeEntity(_lastId);
                updateScore();
                _tick = 0;
                _pokeball = false;
            },
            "", _textures[Textures::PLAYER], _fonts[0],
            {randomFloat(25.0, 1175.0), randomFloat(25.0, 695.0)}, {0.3, 0.3},
            sf::Color::White, 0);

        _lastId = getLastId();
        _pokeball = true;
    }
    // Pokeball removal.
    else if (_gameState == GameState::GAME && _tick == 100) {
        if (_tick == 100) {
            removeEntity(_lastId);
            _life--;
            _tick = 0;
            _pokeball = false;
        }
    } else
        _tick++;
}

void Game::updateScore() {
    removeEntity(_scoreId);
    _score++;
    createText("Score : " + std::to_string(_score), _fonts[0], {70.0, 70.0},
               {1, 1}, sf::Color::White, 0);
    _scoreId = getLastId();
}

void Game::checkLife() {
    if (_life < _lifeId.size()) {
        removeEntity(_lifeId[_life]);
        _lifeId.erase(_lifeId.begin() + _life);
    }
    if (_life == 0 && _gameState == GameState::GAME)
        changeGameState(GameState::GAMEOVER);
}
