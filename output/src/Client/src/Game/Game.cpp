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
    loadTexture("src/Client/assets/Buttons/Button.png");
    loadTexture("src/Client/assets/Buttons/Parameter.png");
    loadTexture("src/Client/assets/Buttons/Quit.png");
    //    loadMusic("src/Client/assets/Sound/music.wav");
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
    _music.setVolume(20);
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

void Game::createClickable(sf::Texture &texture, sf::Vector2f position,
                           sf::Vector2f scale, sf::Color color,
                           float rotation) {
    uint32_t clickable_entity = _gameEngine.getEntityManager()->createEntity();

    sf::Sprite                                        sprite_temp_temp;
    Engine::RendererModule::Components::ClickableData clickable_temp = {
        sprite_temp_temp, position, scale, color, rotation};

    std::shared_ptr<Engine::RendererModule::Components::ClickableComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::ClickableComponent>(
            clickable_temp, texture);

    _gameEngine.getEntityManager()->addComponent(clickable_entity,
                                                 spriteComponent);
    addEntity(clickable_entity);
}

void Game::createButton(std::string text, sf::Texture &texture, sf::Font &font,
                        sf::Vector2f position, sf::Vector2f scale,
                        sf::Color color, float rotation) {
    uint32_t button_entity = _gameEngine.getEntityManager()->createEntity();

    sf::Sprite                                        sprite_temp_temp;
    Engine::RendererModule::Components::ClickableData clickable_temp = {
        sprite_temp_temp, position, scale, color, rotation};

    // calc pos for text
    sf::Vector2f center =
        sf::Vector2f(position.x + (texture.getSize().x * scale.x) / 2,
                     position.y + (texture.getSize().y * scale.y) / 2);

    sf::Vector2f text_pos =
        sf::Vector2f(center.x - (text.size() * 20 * scale.x) / 2,
                     center.y - (20 * scale.y) / 2);

    Engine::RendererModule::Components::TextData text_temp = {
        text, font, color, text_pos, scale, rotation};

    std::shared_ptr<Engine::RendererModule::Components::ClickableComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::ClickableComponent>(
            clickable_temp, texture);

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        titleComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                text_temp);

    _gameEngine.getEntityManager()->addComponent(button_entity,
                                                 spriteComponent);
    _gameEngine.getEntityManager()->addComponent(button_entity, titleComponent);
    addEntity(button_entity);
}

void Game::setMenu() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width) / textureSize.x;
    float scale_y = static_cast<float>(_height) / textureSize.y;
    float scale = std::min(scale_x, scale_y);

    createSprite(_textures[BACKGROUND], {0, 0}, {scale, scale});

    //        title
    createText("Air-Type", _fonts[TITLE],
               {static_cast<float>(_width / 2 - 350),
                static_cast<float>(_height / 2 - 1000)},
               {2, 2});

    // server choice
    createButton("Server Info", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 9 - 350),
                  static_cast<float>(_height / 2 - 500)},
                 {1, 0.8});
    //    server ip

    createButton("Server IP", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 8 - 350),
                  static_cast<float>(_height / 2 - 300)},
                 {1.2, 0.7});
    //    server port
    createButton("Server Ports", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 8 - 350),
                  static_cast<float>(_height / 2 - 100)},
                 {1.2, 0.7});
    //    go to lobby
    createButton("Go To lobby", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 9 - 350),
                  static_cast<float>(_height / 2 + 100)},
                 {1, 0.8});
    //    settings
    createButton("", _textures[PARAMETER_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 1.2 - 350),
                  static_cast<float>(_height / 2 + 400)},
                 {0.15, 0.15});
    //    quit
    createButton("", _textures[QUIT_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 1.13 - 350),
                  static_cast<float>(_height / 2 + 400)},
                 {0.15, 0.15});
}

void Game::setLobby() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width) / textureSize.x;
    float scale_y = static_cast<float>(_height) / textureSize.y;
    float scale = std::min(scale_x, scale_y);

    createSprite(_textures[BACKGROUND], {0, 0}, {scale, scale});

    //        title
    createText("Air-Type", _fonts[TITLE],
               {static_cast<float>(_width / 2 - 350),
                static_cast<float>(_height / 2 - 1000)},
               {2, 2});

    // server choice
    createButton("Choose your Room", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 9 - 350),
                  static_cast<float>(_height / 4)},
                 {1, 0.8});

    createSprite(_textures[BUTTON],
                 {static_cast<float>(_width / 9 - 350),
                  static_cast<float>(_height / 4 + 200)},
                 {1, 3});
    //    settings
    createButton("", _textures[PARAMETER_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 1.2 - 350),
                  static_cast<float>(_height / 2 + 400)},
                 {0.15, 0.15});
    //    quit
    createButton("", _textures[QUIT_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width / 1.13 - 350),
                  static_cast<float>(_height / 2 + 400)},
                 {0.15, 0.15});
}

void Game::setSettings() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width) / textureSize.x;
    float scale_y = static_cast<float>(_height) / textureSize.y;
    float scale = std::min(scale_x, scale_y);

    createSprite(_textures[0], {0, 0}, {scale, scale});

    // SOUND SECTION.
    // Text sound.
    createText(std::to_string(static_cast<int>(_music.getVolume())),
               _fonts[TITLE], {925, 100});
    // Button volume -.
    createSprite(_textures[1], {700, 100}, {0.1, 0.1});
    // Button volume +.
    createSprite(_textures[1], {1150, 100}, {0.1, 0.1});

    // WINDOW_SIZE SECTION.
    // Window 500x500.
    createSprite(_textures[1], {700, 500}, {0.1, 0.1});
    // Window 800x600.
    createSprite(_textures[1], {925, 500}, {0.1, 0.1});
    // Window fullscreen.
    createSprite(_textures[1], {1150, 500}, {0.1, 0.1});
}
