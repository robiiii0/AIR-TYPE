//
// Created by Kl Eddie on 29/11/2023.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "../../../GameEngine/GameEngine.hpp"
#include "../GameState/GameState.hpp"

enum {
    BACKGROUND,
    PARALLAX1,
    PARALLAX2,
    PARALLAX3,
    PLAYER,
    ENEMY,
    BULLET,
    TEXT,
};

enum {
    TITLE,
    SUBTITLE,
};

class Game {
    public:
        Game();
        void run();

        Engine::GameEngine &getGameEngine();

        // Manage Entities
        void                        addEntity(std::uint32_t entity);
        void                        removeEntity(std::uint32_t entity);
        std::vector<std::uint32_t> &getEntities();
        
                void setHomepage();

        // Load Assets
        void loadFont(std::string path);
        void loadTexture(std::string path);

        // Create Component
        void createText(std::string text, sf::Font &font,
                        sf::Vector2f position = {0.0, 0.0},
                        sf::Vector2f scale = {1, 1},
                        sf::Color color = sf::Color::White, float rotation = 0);
        void createSprite(sf::Texture &texture,
                          sf::Vector2f position = {0.0, 0.0},
                          sf::Vector2f scale = {1, 1},
                          sf::Color    color = sf::Color::White,
                          float        rotation = 0);

        // Set Screen

        void setLobby();

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;

        unsigned int _width = sf::VideoMode::getDesktopMode().width;
        unsigned int _height = sf::VideoMode::getDesktopMode().height;

        std::vector<sf::Font>    _fonts;
        sf::Sprite               _sprite;
        std::vector<sf::Texture> _textures;
};

#endif  // GAME_HPP
