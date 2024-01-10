/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "../../../GameEngine/GameEngine.hpp"
#include "../../../GameEngine/HmiModule/HmiModule.hpp"
#include "../../../GameEngine/RendererModule/Components/ClickableComponent/ClickableComponent.hpp"
#include "../../../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.hpp"
#include "../../../GameEngine/RendererModule/Components/TextComponent/TextComponent.hpp"
#include "./GameEnum.hpp"

class Game {
    public:
        Game();
        void run();

        Engine::GameEngine &getGameEngine();

        void                        addEntity(std::uint32_t entity);
        void                        removeEntity(std::uint32_t entity);
        std::vector<std::uint32_t> &getEntities();

        void LoadFont(std::string paths);
        void LoadTexture(std::string paths);
        void LoadTextureButton(std::string paths);
        void LoadSound(std::string paths, bool loop, bool play, float volume);

        void createSprite(
            Engine::Entity::Component::GenericComponents::Vector2f pos,
            Engine::Entity::Component::GenericComponents::Vector2f scale,
            sf::Texture &texture, std::string name);
        void createText(
            std::string text, sf::Font &font,
            Engine::Entity::Component::GenericComponents::Vector2f position,
            Engine::Entity::Component::GenericComponents::Vector2f scale,
            sf::Color color, float rotation);
        void createButton(std::function<void()> func, std::string text,
                          sf::Texture &texture, sf::Font &font,
                          sf::Vector2f position, sf::Vector2f scale,
                          sf::Color color, float rotation);

        void setMenu();
        void setGame();

        void changeGameState(GameState state);
        void clearCurrentState();
        void setUpState();

        void handleExit();

    private:
        Engine::GameEngine         _gameEngine;
        std::vector<std::uint32_t> _entities;

        int _screenWidth;
        int _screenHeight;
        int _gameState;

        std::vector<sf::Font>    _fonts;
        std::vector<sf::Texture> _textures;
        std::vector<sf::Texture> _texturesButton;

        std::vector<
            std::shared_ptr<Engine::RendererModule::Components::SoundComponent>>
                                           _sounds;
        std::shared_ptr<Engine::HmiModule> _hmiModule;
};

#endif /* !GAME_HPP_ */
