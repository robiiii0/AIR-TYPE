/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameMenuManagement
*/

#include "../Game.hpp"

void Game::setMenu() {
    createSprite({0.0, 0.0}, {2, 1.7}, _textures[0], "");
    createButton(std::bind(&Game::changeGameState, this, GameState::GAME), "",
                 _textures[1], _fonts[0],
                 {static_cast<float>(_screenWidth / 2),
                  static_cast<float>(_screenHeight / 1.5)},
                 {1, 1}, sf::Color::White, 0);
    // createSprite({static_cast<float>(_screenWidth + 300) / 2,
    //               static_cast<float>(_screenHeight) / 8},
    //              {0.3, 0.3}, _textures[LUGIA], "");
    // createSprite({static_cast<float>(_screenWidth) / 10,
    //               static_cast<float>(_screenHeight / 3)},
    //              {0.4, 0.4}, _textures[INFERNIX], "");
    createText("PokeCatcher", _fonts[0],
               {static_cast<float>(_screenWidth / 2),
                static_cast<float>(_screenHeight / 5)},
               {2, 2}, sf::Color::Black, 0);
    createText("Catch the ball to begin", _fonts[0],
               {static_cast<float>(_screenWidth / 2),
                static_cast<float>(_screenHeight / 3)},
               {1.5, 1.5}, sf::Color::Black, 0);
}
