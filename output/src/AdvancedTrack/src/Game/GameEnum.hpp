/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameEnum
*/

#ifndef GAMEENUM_HPP_
#define GAMEENUM_HPP_

#include <SFML/Graphics.hpp>

enum GameState {
    MENU,
    GAME,
    SETTINGS,
    KEYBINDING,
    PAUSE,
    GAMEOVER,
    EXIT,
};

enum Key {
    UP = sf::Keyboard::Up,
    DOWN = sf::Keyboard::Down,
    LEFT = sf::Keyboard::Left,
    RIGHT = sf::Keyboard::Right,
    ATTACK = sf::Keyboard::Space,
    ESCAPE = sf::Keyboard::Escape,
};

enum Textures {
    BACKGROUND,
    PLAYER,
};

#endif /* !GAMEENUM_HPP_ */
