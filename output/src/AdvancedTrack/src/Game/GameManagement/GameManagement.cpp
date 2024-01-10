/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    createSprite({static_cast<float>(0), static_cast<float>(0)},
                 {static_cast<float>(2), static_cast<float>(2)}, _textures[0],
                 "");
    createSprite({static_cast<float>(100), static_cast<float>(100)},
                 {static_cast<float>(1), static_cast<float>(1)}, _textures[1],
                 "");
}
