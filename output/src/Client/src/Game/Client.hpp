//
// Created by Kl Eddie on 29/11/2023.
//

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <functional>
#include <string>
#include <vector>

#include "../../../GameEngine/GameEngine.hpp"
#include "../../../GameEngine/HmiModule/HmiModule.hpp"
#include "../../../GameEngine/NetworkingModule/NetworkingModule.hpp"
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

class Client {
    public:
        Client();
        void run();
        void applyStatus(Engine::Network::Client &client);

        Engine::GameEngine &getGameEngine();

        // Manage Entities
        void                        addEntity(std::uint32_t entity);
        void                        removeEntity(std::uint32_t entity);
        std::vector<std::uint32_t> &getEntities();

        // Load Assets
        void loadFont(std::string path);
        void loadTexture(std::string path);
        void testMessage();

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

        void attack();
        void createMissile(std::uint32_t id, float x, float y);

        // Set Screen
        void setMenu();
        void setParallax();
        //        void setLobby();
        void setSettings();
        void InitGame();

        void GameStart();
        // void Setting();

        void changeState(int state);
        void clearCurrentState();
        void setupState();

        // Sound Settings
        void SoundUp();
        void SoundLess();

        // Window size settings
        void WindowSize500();
        void WindowSize800();
        void WindowSizeFullscreen();



        void createParallax(std::vector<sf::Texture> &Textures);
        void ConnectionWithServer();

        // std::vector<sf::Texture> LoadTextures(std::vector<std::string> paths);
        void LoadTexture(std::string paths);

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;
        int                        _ClientId;

        int  _screenWidth;
        int _screenHeight;

        std::vector<sf::Font>    _fonts;
        std::vector<sf::Texture> _texturesParallax;
        std::vector<sf::Texture> _texturesButton;
        
        std::shared_ptr<Engine::RendererModule::Components::SoundComponent> _sounds;
        std::shared_ptr<Engine::Network::NetworkingModule> _networkingModule;
        std::shared_ptr<Engine::HmiModule>                 _hmiModule;
};

#endif  // GAME_HPP
