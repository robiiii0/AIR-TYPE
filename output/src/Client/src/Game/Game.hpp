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

        void                        addEntity(std::uint32_t entity);
        void                        removeEntity(std::uint32_t entity);
        std::vector<std::uint32_t> &getEntities();

        void setLobby();
    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;

        sf::Font _font;
};

#endif  // GAME_HPP
