/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameStateManagement
*/

#include "../Game.hpp"

void Game::changeGameState(GameState state) {
    clearCurrentState();
    _gameState = state;
    setUpState();
}

void Game::clearCurrentState() {
    _entities.clear();
    for (auto entity : _entities) {
        std::cout << "destruction de l'entitée " << entity << std::endl;
        _gameEngine.getEntityManager()->destroyEntity(entity);
    }
}

void Game::setUpState() {
    switch (_gameState) {
        case GameState::MENU:
            setMenu();
            break;
        case GameState::GAME:
            setGame();
            break;
        case GameState::GAMEOVER:
            setGameOver();
            break;
        default:
            break;
    }
}
