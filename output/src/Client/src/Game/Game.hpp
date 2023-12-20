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

        void createText(std::string text, sf::Font &font,
                        sf::Vector2f position = {0.0, 0.0},
                        sf::Vector2f scale = {1, 1},
                        sf::Color color = sf::Color::White, float rotation = 0);
        void createSprite(sf::Sprite sprite, sf::Texture &texture,
                        sf::Vector2f position = {0.0, 0.0},
                        sf::Vector2f scale = {10, 10},
                        sf::Color color = sf::Color::White, float rotation = 0);
        void setLobby();

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;

        unsigned int _width = sf::VideoMode::getDesktopMode().width;
        unsigned int _height = sf::VideoMode::getDesktopMode().height;

        sf::Font _font;
        sf::Sprite _sprite;
        sf::Texture _texture;
};

#endif  // GAME_HPP
