/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    createSprite({static_cast<float>(100), static_cast<float>(100)}, {static_cast<float>(1), static_cast<float>(1)}, _textures[0], "");
}
