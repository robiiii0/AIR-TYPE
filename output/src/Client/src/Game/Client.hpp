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

        void attack();
        void createMissile(std::uint32_t id, float x, float y);

        void createBackground(sf::Texture &texture);
        void createParallax(std::vector<sf::Texture> &Textures);
        void createPlayer(std::vector<sf::Texture> &Textures);
        void createButton(std::function<void()> func, std::string text,
                          sf::Texture &texture, sf::Font &font,
                          sf::Vector2f position, sf::Vector2f scale,
                          sf::Color color, float rotation);
        void createText(std::string text, sf::Font &font, sf::Vector2f position,
                        sf::Vector2f scale, sf::Color color, float rotation);

        // std::vector<sf::Texture> LoadTextures(std::vector<std::string>
        // paths);
        void LoadTextureParallax(std::string paths);
        void LoadTexturePlayer(std::string paths);
        void LoadBackground();
        void LoadFont(std::string paths);
        void LoadTextureButton(std::string paths);

        void setMenu();
        void ConnectionWithServer();

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;
        int                        _ClientId;

        int _screenWidth;
        int _screenHeight;

        std::vector<sf::Font>    _fonts;
        std::vector<sf::Texture> _texturesParallax;
        std::vector<sf::Texture> _texturePlayer;
        std::vector<sf::Texture> _texturesButton;
        sf::Texture              _backgroundTexture;

        std::shared_ptr<Engine::RendererModule::Components::SoundComponent>
                                                           _sounds;
        std::shared_ptr<Engine::Network::NetworkingModule> _networkingModule;
        std::shared_ptr<Engine::HmiModule>                 _hmiModule;
};

#endif  // GAME_HPP