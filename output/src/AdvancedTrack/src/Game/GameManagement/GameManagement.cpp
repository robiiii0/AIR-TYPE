/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameGameManagement
*/

#include "../Game.hpp"

void Game::setGame() {
    createSprite({0.0, 0.0}, {2.0, 2.0}, _textures[Textures::BACKGROUND], "");
    createSprite({300.0, 300.0}, {1.0, 1.0}, _textures[Textures::PLAYER], "");
}
