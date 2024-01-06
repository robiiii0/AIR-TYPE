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
#include "../../../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.hpp"
#include "../../../GameEngine/RendererModule/Components/EnemyComponent/EnemyComponent.hpp"

enum GameState {
    MENU,
    GAME,
    SETTINGS,
    KEYBINDING,
    PAUSE,
    GAMEOVER,
    EXIT,
};

class Client {
        enum Key {
            UP = sf::Keyboard::Up,
            DOWN = sf::Keyboard::Down,
            LEFT = sf::Keyboard::Left,
            RIGHT = sf::Keyboard::Right,
            ATTACK = sf::Keyboard::Space,
            ENTER = sf::Keyboard::Return,
            ESCAPE = sf::Keyboard::Escape,
        };

        enum KeyBindingSprite {
            UP_TEXTURE = 0,
            DOWN_TEXTURE = 1,
            LEFT_TEXTURE = 2,
            RIGHT_TEXTURE = 3,
            ATTACK_TEXTURE = 4,
            ENTER_TEXTURE = 5,
            ESCAPE_TEXTURE = 6,
        };

    public:
        Client();
        void run();
        void applyStatus(Engine::Network::Client &client);

        Engine::GameEngine &getGameEngine();
        // Manage Entities
        void                        addEntity(std::uint32_t entity);
        void                        removeEntity(std::uint32_t entity);
        std::vector<std::uint32_t> &getEntities();

        void attack();
        void createMissile(std::uint32_t id, float x, float y);

        void CreateSprite(
            Engine::Entity::Component::GenericComponents::Vector2f pos,
            Engine::Entity::Component::GenericComponents::Vector2f scale,
            sf::Texture &texture, std::string name);
        void createBackground(sf::Texture &texture);
        void createParallax(std::vector<sf::Texture> &Textures);
        void createPlayer(std::vector<sf::Texture> &Textures);
        void createEnemy(std::vector<sf::Texture> &Textures);
        void createButton(std::function<void()> func, std::string text,
                          sf::Texture &texture, sf::Font &font,
                          sf::Vector2f position, sf::Vector2f scale,
                          sf::Color color, float rotation);
        void createText(
            std::string text, sf::Font &font,
            Engine::Entity::Component::GenericComponents::Vector2f position,
            Engine::Entity::Component::GenericComponents::Vector2f scale,
            sf::Color color, float rotation);

        // std::vector<sf::Texture> LoadTextures(std::vector<std::string>
        // paths);
        void LoadTextureParallax(std::string paths);
        void LoadTexturePlayer(std::string paths);
        void LoadBackground();
        void LoadSettingsKeyBindings(std::string paths);
        void LoadFont(std::string paths);
        void LoadTextureButton(std::string paths);

        void LoadTextureMissile(std::string paths);
        void LoadTextureEnemies(std::string paths);
        void LoadSound(std::string paths, bool loop, bool play, float volume);

        void setMenu();
        void setSettings();
        void setGame();
        void ChangeKeyBinding();
        void ConnectionWithServer();

        // Gamestate handling
        void changeState(GameState state);
        void clearCurrentState();
        void setupState();

        void handleExit();

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;
        int                        _ClientId;

        int _screenWidth;
        int _screenHeight;
        int _gameState;

        std::vector<sf::Font>    _fonts;
        std::vector<sf::Texture> _texturesParallax;
        std::vector<sf::Texture> _texturePlayer;
        std::vector<sf::Texture> _texturesEnemies;
        std::vector<sf::Texture> _textureSetting;
        std::vector<sf::Texture> _texturesButton;
        sf::Texture              _backgroundTexture;
        sf::Texture              _textureMissile;

        std::vector<
            std::shared_ptr<Engine::RendererModule::Components::SoundComponent>>
                                                           _sounds;
        std::unique_ptr<Engine::Network::NetworkingModule> _networkingModule;
        std::shared_ptr<Engine::HmiModule>                 _hmiModule;
};

#endif  // GAME_HPP
