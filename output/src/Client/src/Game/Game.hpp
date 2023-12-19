//
// Created by Kl Eddie on 29/11/2023.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "../../../GameEngine/GameEngine.hpp"
#include "../GameState/GameState.hpp"

class Game {
    public:
        Game();
        void run();

        Engine::GameEngine &getGameEngine();

    private:
        Engine::GameEngine _gameEngine;  // TODO: fix this
        //    GameState* currentState;
        //    void changeState();
};

#endif  // GAME_HPP
