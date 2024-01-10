/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameMenuManagement
*/

#include "../Game.hpp"

void Game::setMenu() {
    createText(
        "Hello", _fonts[0], {static_cast<float>(100), static_cast<float>(100)},
        {static_cast<float>(1), static_cast<float>(1)}, sf::Color::White, 0);
}
