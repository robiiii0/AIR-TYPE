//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _gameEngine.getRendererModule()->init(
        int(sf::VideoMode::getDesktopMode().width),
        int(sf::VideoMode::getDesktopMode().height), "Air-Type", 60);
    loadFont("src/Client/assets/Fonts/Roboto-Regular.ttf");
    loadTexture("src/Client/assets/new_assets/background/bg-preview-big.png");
    loadTexture("src/Client/assets/Background/Layers/layer02_cake.png");
    loadMusic("src/Client/assets/Sound/music.wav");
}

void Game::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update();
        _gameEngine.getRendererModule()->handleEvent(
            *_gameEngine.getEntityManager(),
            _gameEngine.getEntityManager()->getNbEntites());
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
}

Engine::GameEngine &Game::getGameEngine() { return _gameEngine; }

void Game::addEntity(std::uint32_t entity) { _entities.push_back(entity); }

void Game::removeEntity(std::uint32_t entity) {
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity),
                    _entities.end());
}

std::vector<std::uint32_t> &Game::getEntities() { return _entities; }

void Game::loadFont(std::string path) {
    sf::Font font;
    if (!font.loadFromFile(path)) {
        std::cout << "cant load: " << path << std::endl;
    }
    _fonts.push_back(font);
}

void Game::loadTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cout << "cant load: " << path << std::endl;
    }
    texture.setSmooth(true);
    _textures.push_back(texture);
}

void Game::loadMusic(std::string path) {
    if (!_music.openFromFile(path)) {
        std::cout << "cant load: " << path << std::endl;
    }
    _music.setLoop(true);
    _music.setVolume(50);
    _music.play();
    std::cout << "sound loaded" << std::endl;
}

void Game::createText(std::string text, sf::Font &font, sf::Vector2f position,
                      sf::Vector2f scale, sf::Color color, float rotation) {
    uint32_t textEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::TextData text_temp = {
        text, font, color, position, scale, rotation};

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        titleComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                text_temp);

    _gameEngine.getEntityManager()->addComponent(textEntity, titleComponent);
    addEntity(textEntity);
}

void Game::createSprite(sf::Texture &texture, sf::Vector2f position,
                        sf::Vector2f scale, sf::Color color, float rotation) {
    uint32_t spriteEntity = _gameEngine.getEntityManager()->createEntity();

    sf::Sprite                                     sprite_temp_temp;
    Engine::RendererModule::Components::SpriteData sprite_temp = {
        sprite_temp_temp, position, scale, color, rotation};

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 texture);

    _gameEngine.getEntityManager()->addComponent(spriteEntity, spriteComponent);
    addEntity(spriteEntity);
}

void Game::setSettings() {
    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width) / textureSize.x;
    float scale_y = static_cast<float>(_height) / textureSize.y;
    float scale = std::min(scale_x, scale_y);

    createSprite(_textures[0], {0, 0}, {scale, scale});

    // SOUND SECTION.
    // Text sound.
    createText(std::to_string(static_cast<int>(_music.getVolume())), _fonts[TITLE], {925, 100});
    // Button volume -.
    createSprite(_textures[1], {700, 100}, {0.1, 0.1});
    // Button volume +.
    createSprite(_textures[1], {1150, 100}, {0.1, 0.1});


    // WINDOW_SIZE SECTION.
}

