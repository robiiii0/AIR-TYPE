//
// Created by Kl Eddie on 29/11/2023.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../GameState/GameState.hpp"
#include "../../../GameEngine/GameEngine.hpp"


class Game {
public:
    Game();
    void run();
private:
    Engine::GameEngine _gameEngine;
//    GameState* currentState;
//    void changeState();
};


#endif //GAME_HPP
