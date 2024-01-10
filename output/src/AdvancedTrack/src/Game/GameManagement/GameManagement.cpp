/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    createSprite({static_cast<float>(0), static_cast<float>(0)},
                 {static_cast<float>(2), static_cast<float>(2)},
                 _textures[Textures::BACKGROUND], "");
    createSprite({static_cast<float>(100), static_cast<float>(100)},
                 {static_cast<float>(1), static_cast<float>(1)},
                 _textures[Textures::PLAYER], "");
}
