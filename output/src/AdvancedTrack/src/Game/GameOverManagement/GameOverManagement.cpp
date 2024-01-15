/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameOverManagement
*/

#include "../Game.hpp"

void Game::setGameOver() {
    createSprite({0.0, 0.0}, {2, 1.7}, _textures[0], "");
    createText("Game Over", _fonts[0],
               {static_cast<float>(_screenWidth / 2),
                static_cast<float>(_screenHeight / 5)},
               {2, 2}, sf::Color::Black, 0);
    createText("You caught " + std::to_string(_score) + " pokemons", _fonts[0],
               {static_cast<float>(_screenWidth / 2),
                static_cast<float>(_screenHeight / 3)},
               {1.5, 1.5}, sf::Color::Black, 0);
    createButton(std::bind(&Game::changeGameState, this, GameState::MENU),
                 "Retry to Catch", _textures[1], _fonts[0],
                 {static_cast<float>(_screenWidth - 100),
                  static_cast<float>(_screenHeight - 100)},
                 {0.5, 0.5}, sf::Color::White, 0);
}
