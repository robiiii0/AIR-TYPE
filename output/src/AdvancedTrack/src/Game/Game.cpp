/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** Game
*/

#include "Game.hpp"

Game::Game() : _gameEngine() {
    _gameState = GameState::MENU;
}

void Game::run() {
}

void Game::handleExit() {
    _gameState = GameState::EXIT;
}
