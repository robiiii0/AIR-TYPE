/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** main
*/

#include "../../GameEngine/GameEngine.hpp"
#include "./Game/Game.hpp"

int main() {
    Game game;

    // game.setMenu();
    game.setParalax();
        game.setLobby();
    //    game.setSettings();
    game.run();
    return 0;
}
