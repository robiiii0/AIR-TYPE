//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _gameEngine.getRendererModule()->init(
        int(sf::VideoMode::getDesktopMode().width),
        int(sf::VideoMode::getDesktopMode().height), "Air-Type", 60);
    _width_drawable = _gameEngine.getRendererModule()->getWindow().getSize().x;
    _height_drawable = _gameEngine.getRendererModule()->getWindow().getSize().y;
    loadFont("src/Client/assets/Fonts/Roboto-Regular.ttf");
    loadTexture("src/Client/assets/new_assets/background/bg-preview-big.png");
    loadTexture("src/Client/assets/Buttons/Button.png");
    loadTexture("src/Client/assets/Buttons/SettingWhite.png");
    loadTexture("src/Client/assets/Buttons/Quit.png");

    loadTexture("src/Client/assets/new_assets/background/layered/bg-stars.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/earth.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/Galaxy.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/nomansland.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/asteroid.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/blackhole.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/gaz.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/ice.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/lava.png");
    loadTexture("src/Client/assets/new_assets/background/Menu/moon.png");
    loadTexture(
        "src/Client/assets/new_assets/background/Menu/noatmosphere.png");

    // loadTexture("src/Client/assets/new_assets/background/parallax/3.png");
    // loadTexture("src/Client/assets/new_assets/background/parallax/4.png");

    loadMusic("src/Client/assets/Sound/music.wav");
}

void Game::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        _gameEngine.getRendererModule()->handleEvent(
            *_gameEngine.getEntityManager(), getEntities());
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

void Game::createSpriteParallax(sf::Texture &_texture, std::string _name,
                                std::pair<float, float> _pos,
                                std::pair<float, float> _scale,
                                std::pair<float, float> _movement,
                                bool isAnimated, sf::IntRect rect) {
    uint32_t spriteParallaxEntity =
        _gameEngine.getEntityManager()->createEntity();
    sf::Sprite sprite_temp;

    Engine::RendererModule::Components::parallaxData parallaxData = {
        sprite_temp, _name, _pos, _scale, _movement, isAnimated, rect, sf::Clock()};

    std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
        parallaxComponent = std::make_shared<
            Engine::RendererModule::Components::parallaxComponent>(parallaxData,
                                                                   _texture);
    _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                 parallaxComponent);
    addEntity(spriteParallaxEntity);
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

    Engine::RendererModule::Components::TextData text_temp = {
        text, font, color, position, scale, rotation};

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

    std::cout << "width: " << _width << std::endl;
    std::cout << "height: " << _height << std::endl;
    std::cout << "texture width: " << textureSize.x << std::endl;
    std::cout << "texture height: " << textureSize.y << std::endl;
    float scale_x = static_cast<float>(_width_drawable) / textureSize.x;
    float scale_y = static_cast<float>(_height_drawable) / textureSize.y;
    float scale = std::max(scale_x, scale_y);

    createSprite(_textures[BACKGROUND],
                 {static_cast<float>(_width_drawable / 2),
                  static_cast<float>(_height_drawable / 2)},
                 {scale, scale});

    //        title
    createText("Air-Type", _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 6)},
               {1, 1});

    // server choice
    createButton("Server Info", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 6),
                  static_cast<float>(_height_drawable / 3)},
                 {0.6, 0.5});
    //    server ip

    createButton("Server IP", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 5),
                  static_cast<float>(_height_drawable / 2.2)},
                 {0.8, 0.5});
    //    //    server port
    createButton("Server Ports", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 5),
                  static_cast<float>(_height_drawable / 1.8)},
                 {0.8, 0.5});
    //    //    go to lobby
    createButton("Go To lobby", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 6),
                  static_cast<float>(_height_drawable / 1.5)},
                 {0.6, 0.5});
    //    //    settings
    createButton("", _textures[PARAMETER_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 1.12),
                  static_cast<float>(_height_drawable / 1.05)},
                 {0.10, 0.10});
    //    //    quit
    createButton("", _textures[QUIT_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 1.05),
                  static_cast<float>(_height_drawable / 1.05)},
                 {0.10, 0.10});
}


void Game::createRoundedButton(
    std::string text,
                          sf::Font &font, sf::Vector2f position,
                          sf::Vector2f scale,
                          sf::Color    colorButton,
                            sf::Color    colorText, std::function<void()> _func
)
{
    uint32_t button_entity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::RoundedClickableData clickable_temp = {
        {position.x, position.y}, {scale.x, scale.y}, colorButton};

    Engine::RendererModule::Components::TextData text_temp = {
        text, font, colorText, {position.x + (scale.x / 2), position.y + (scale.y / 3)}, {1,1}};

    std::shared_ptr<Engine::RendererModule::Components::RoundedClickableComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::RoundedClickableComponent>(
            clickable_temp, _func);

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        titleComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                text_temp);

    _gameEngine.getEntityManager()->addComponent(button_entity,
                                                 spriteComponent);
    _gameEngine.getEntityManager()->addComponent(button_entity, titleComponent);
    addEntity(button_entity);
}

void Game::setParalax() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width_drawable) / textureSize.x;
    float scale_y = static_cast<float>(_height_drawable) / textureSize.y;

    float scale = std::max(scale_x, scale_y);
    std::cout << scale << std::endl;
    const float myRef = {static_cast<float>(1.0)};

    // Background texture

    createSpriteParallax(
        _textures[STARS], "Background",
        {static_cast<float>(_width_drawable),
         static_cast<float>(_height_drawable / 2)},
        {5, 5}, {static_cast<float>(-3.0), static_cast<float>(0.0)}, false);
    createSpriteParallax(
        _textures[STARS], "Background",
        {static_cast<float>(_width_drawable * 2),
         static_cast<float>(_height_drawable / 2)},
        {5, 5}, {static_cast<float>(-3.0), static_cast<float>(0.0)}, false);
    createSpriteParallax(
        _textures[STARS], "Background",
        {static_cast<float>(_width_drawable * 3),
         static_cast<float>(_height_drawable / 2)},
        {5, 5}, {static_cast<float>(-3.0), static_cast<float>(0.0)}, false);

    createSpriteParallax(_textures[EARTH], "Background",
                         {static_cast<float>(_width_drawable),
                          static_cast<float>(_height_drawable / 2)},
                         {0.3, 0.3},
                         {static_cast<float>(-6.0), static_cast<float>(0.0)},
                         true, sf::IntRect(0, 0, 1000, 1000));

    createSpriteParallax(_textures[Galaxy], "Background",
                         {static_cast<float>(_width_drawable + (500 * 1)),
                          static_cast<float>(_height_drawable / 3)},
                         {0.3, 0.3},
                         {static_cast<float>(-6.0), static_cast<float>(3.0)},
                         true, sf::IntRect(0, 0, 1000, 1000));

    createSpriteParallax(_textures[NOMANSLAND], "Background",
                         {static_cast<float>(_width_drawable + (500 * 2)),
                          static_cast<float>(_height_drawable / 2)},
                         {0.3, 0.3},
                         {static_cast<float>(-6.0), static_cast<float>(-7.0)},
                         true, sf::IntRect(0, 0, 1000, 1000));
    createSpriteParallax(_textures[ICE], "Background",
                         {static_cast<float>(_width_drawable + (500 * 3)),
                          static_cast<float>(_height_drawable / 2)},
                         {0.3, 0.3},
                         {static_cast<float>(-6.0), static_cast<float>(4.0)},
                         true, sf::IntRect(0, 0, 1000, 1000));

    createRoundedButton("Play",
                          _fonts[TITLE],{static_cast<float>(_width_drawable / 2 - 100), static_cast<float>(_height_drawable / 2)},
                          {200, 100},
                          sf::Color::Red, sf::Color::White,  std::bind(&Game::GameStart, this));

    createText("Air-Type", _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 5)},
               {2, 2});
}


void Game::GameStart()
{
    std::cout << "le jeu se lance" << std::endl;
    // _gameEngine.getEntityManager()->removeComponent(getEntities(), );
}

void Game::setLobby() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width_drawable) / textureSize.x;
    float scale_y = static_cast<float>(_height_drawable) / textureSize.y;
    float scale = std::max(scale_x, scale_y);

    createSprite(_textures[BACKGROUND],
                 {static_cast<float>(_width_drawable / 2),
                  static_cast<float>(_height_drawable / 2)},
                 {scale, scale});

    //        title
    createText("Air-Type", _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 5)},
               {2, 2});

    // server choice
    createButton("Choose your Room", _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 9),
                  static_cast<float>(_height_drawable / 4)},
                 {1, 0.8});

    createSprite(_textures[BUTTON],
                 {static_cast<float>(_width_drawable / 9),
                  static_cast<float>(_height_drawable / 2)},
                 {1, 3});
    //    //    settings
    createButton("", _textures[PARAMETER_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 1.12),
                  static_cast<float>(_height_drawable / 1.05)},
                 {0.10, 0.10});
    //    //    quit
    createButton("", _textures[QUIT_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 1.05),
                  static_cast<float>(_height_drawable / 1.05)},
                 {0.10, 0.10});
}

void Game::setSettings() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width_drawable) / textureSize.x;
    float scale_y = static_cast<float>(_height_drawable) / textureSize.y;
    float scale = std::max(scale_x, scale_y);

    createSprite(_textures[BACKGROUND],
                 {static_cast<float>(_width_drawable / 2),
                  static_cast<float>(_height_drawable / 2)},
                 {scale, scale});
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
