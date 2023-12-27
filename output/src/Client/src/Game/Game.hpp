//
// Created by Kl Eddie on 29/11/2023.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>
#include <vector>

#include "../../../GameEngine/GameEngine.hpp"
#include "../../../GameEngine/PhysicModule/Components/MovementComponent/MovementComponent.hpp"
#include "../../../GameEngine/PhysicModule/Components/TransformComponent/TransformComponent.hpp"
#include "../../../GameEngine/RendererModule/Components/InputComponent/InputComponent.hpp"

// #include "../GameState/GameState.hpp"

enum {
    BACKGROUND = 0,
    BUTTON,
    PARAMETER_BUTTON,
    QUIT_BUTTON,
    STARS,
    EARTH,
    Galaxy,
    NOMANSLAND,
    ASTEROID,
    BLACKHOLE,
    GAZ,
    ICE,
    LAVA,
    MOON,
    NOATMOSPHERE,
    PLAYER,
    ENEMY,
    BULLET,
    TEXT,
};

enum {
    MENU = 0,
    SETTINGS,
    LOBBY,
    GAME
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
                          float rotation = 0, bool playable = false);

        void createSpriteParallax(sf::Texture &_texture,
                                  std::string  _name = "parallaxSprite",
                                  std::pair<float, float> _pos = {0, 0},
                                  std::pair<float, float> _scale = {1, 1},
                                  std::pair<float, float> _movement = {1, 1},
                                  bool                    isAnimated = false,
                                  sf::IntRect rect = {0, 0, 1920, 1080});

        void createClickable(sf::Texture &texture,
                             sf::Vector2f position = {0.0, 0.0},
                             sf::Vector2f scale = {1, 1},
                             sf::Color    color = sf::Color::White,
                             float        rotation = 0);

        void createButton(std::function<void()> func, std::string text,
                          sf::Texture &texture, sf::Font &font,
                          sf::Vector2f position = {0.0, 0.0},
                          sf::Vector2f scale = {1, 1},
                          sf::Color    color = sf::Color::White,
                          float        rotation = 0);

        void createInput(sf::Font &font, sf::Texture &texture,
                         sf::Vector2f position = {0.0, 0.0},
                         sf::Vector2f scale = {1, 1},
                         sf::Color    color = sf::Color::White,
                         float        rotation = 0);

        void createSound(std::string path, float volume = 50, bool loop = false,
                         bool play = false);

        void createRoundedButton(
            std::string text, sf::Font &font,
            sf::Vector2f position = {0.0, 0.0}, sf::Vector2f scale = {1, 1},
            sf::Color             colorButton = sf::Color::White,
            sf::Color             colorText = sf::Color::White,
            std::function<void()> _func = []() {});

        // Set Screen
        void setMenu();
        void setParalax();
        void setLobby();
        void setSettings();
        void InitGame();

        void GameStart();
        // void Setting();

        void changeState(int state);
        void clearCurrentState();
        void setupState();

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;
        int                        _gameState;

        unsigned int _width = sf::VideoMode::getDesktopMode().width;
        unsigned int _height = sf::VideoMode::getDesktopMode().height;

        unsigned int _width_drawable;
        unsigned int _height_drawable;

        std::vector<sf::Font>    _fonts;
        std::vector<sf::Texture> _textures;
        std::vector<
            std::shared_ptr<Engine::RendererModule::Components::SoundComponent>>
                   _sounds;
        sf::Sprite _sprite;
};

#endif  // GAME_HPP
