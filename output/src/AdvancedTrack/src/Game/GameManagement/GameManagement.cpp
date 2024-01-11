/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    createSprite({0.0, 0.0}, {2.0, 1.7}, _textures[Textures::BACKGROUND], "");
    createButton(std::bind(&Game::changeGameState, this, GameState::MENU),
                 "Go Back", _textures[1], _fonts[0],
                 {static_cast<float>(_screenWidth / 1.05),
                  static_cast<float>(_screenHeight / 1.05)},
                 {0.3, 0.3}, sf::Color::White, 0);
    createSprite({300.0, 300.0}, {1.0, 1.0}, _textures[Textures::PLAYER], "");
}
