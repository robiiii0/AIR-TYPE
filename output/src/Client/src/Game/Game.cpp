//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _sounds.clear();
    _gameEngine.getRendererModule()->init(
        int(sf::VideoMode::getDesktopMode().width),
        int(sf::VideoMode::getDesktopMode().height), "Air-Type", 60);
    _width_drawable = _gameEngine.getRendererModule()->getWindow().getSize().x;
    _height_drawable = _gameEngine.getRendererModule()->getWindow().getSize().y;
    _gameState = MENU;
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
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
    loadTexture(
        "src/Client/assets/new_assets/player/sprites/player1_yellow.png");
    // loadTexture("src/Client/assets/new_assets/background/parallax/3.png");
    // loadTexture("src/Client/assets/new_assets/background/parallax/4.png");

    // Main music loop.
    // createSound("src/Client/assets/Sound/music.wav", 50, true, true);
}

void Game::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getPhysicModule()->update(*_gameEngine.getEntityManager(),
                                              getEntities(), 1.0f / 60.0f);
        _hmiModule->keyEvent(
            _gameEngine.getRendererModule()->UpdateForServer());
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        _gameEngine.getRendererModule()->handleEvent(
            *_gameEngine.getEntityManager(), getEntities());

        if (_networkingModule != nullptr) {
            for (auto &client :
                 _networkingModule->getClients()) {  // ? client update
                while (client.getBuffer()->hasPacket()) {
                    std::string msg = client.getBuffer()->readNextPacket();
                    if (msg == "STATUS START") {
                        applyStatus(client);
                    }
                }
            }
        }
        std::vector<uint32_t> result = getEntities();
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
}

void Game::applyStatus(Engine::Network::Client &client) {
    std::string msg = client.getBuffer()->readNextPacket();
    while (msg != "STATUS END") {
        if (msg.find("Player") != std::string::npos) {
            std::vector<std::string> player_info;
            while (msg.find(" ") != std::string::npos) {
                player_info.emplace_back(msg.substr(0, msg.find(" ")));
                std::cout << msg << std::endl;
                msg.erase(0, msg.find(" ") + 1);
            }
            if (msg.find(" ") == std::string::npos) {
                player_info.emplace_back(msg);
            }
            std::cout << "player_info: "
                      << " " << player_info[3] << " " << player_info[2]
                      << std::endl;
            createSprite(_textures[PLAYER],
                         {std::stof(player_info[2]), std::stof(player_info[3])},
                         {2, 2}, sf::Color::White, 0, true);
        }
        msg = client.getBuffer()->readNextPacket();
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

void Game::createSound(std::string path, float volume, bool loop, bool play) {
    uint32_t soundEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::SoundData sound_temp = {path, loop,
                                                                play, volume};

    std::shared_ptr<Engine::RendererModule::Components::SoundComponent>
        soundComponent = std::make_shared<
            Engine::RendererModule::Components::SoundComponent>(sound_temp);

    _gameEngine.getEntityManager()->addComponent(soundEntity, soundComponent);
    addEntity(soundEntity);
    _sounds.push_back(soundComponent);
    std::cout << "SOUND CREATED!" << std::endl;
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
        sprite_temp, _name,      _pos, _scale,
        _movement,   isAnimated, rect, sf::Clock()};

    std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
        parallaxComponent = std::make_shared<
            Engine::RendererModule::Components::parallaxComponent>(parallaxData,
                                                                   _texture);
    _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                 parallaxComponent);
    addEntity(spriteParallaxEntity);
}

void Game::createSprite(sf::Texture &texture, sf::Vector2f position,
                        sf::Vector2f scale, sf::Color color, float rotation,
                        bool playable) {
    uint32_t spriteEntity = _gameEngine.getEntityManager()->createEntity();

    sf::Sprite sprite_temp_temp;

    Engine::RendererModule::Components::SpriteData sprite_temp = {
        sprite_temp_temp, position, scale, color, rotation, playable};

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

void Game::createButton(std::function<void()> func, std::string text,
                        sf::Texture &texture, sf::Font &font,
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
            clickable_temp, texture, func);

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        titleComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                text_temp);

    _gameEngine.getEntityManager()->addComponent(button_entity,
                                                 spriteComponent);
    _gameEngine.getEntityManager()->addComponent(button_entity, titleComponent);
    addEntity(button_entity);
}

void Game::createInput(sf::Font &font, sf::Texture &texture,
                       sf::Vector2f position, sf::Vector2f scale,
                       sf::Color color, float rotation) {
    uint32_t input_entity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::InputData input_temp = {
        position, scale, color, rotation};

    Engine::RendererModule::Components::SpriteData sprite_temp = {
        _sprite, position, scale, color, rotation, true};

    std::shared_ptr<Engine::RendererModule::Components::InputComponent>
        inputComponent = std::make_shared<
            Engine::RendererModule::Components::InputComponent>(input_temp,
                                                                font);

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 texture);

    _gameEngine.getEntityManager()->addComponent(input_entity, spriteComponent);
    _gameEngine.getEntityManager()->addComponent(input_entity, inputComponent);
    addEntity(input_entity);
}

void Game::setMenu() {
    //        title
    createText("Air-Type", _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 6)},
               {1, 1});

    //    // server choice
    //    createSprite(_textures[BUTTON],
    //                 {static_cast<float>(_width_drawable / 6),
    //                  static_cast<float>(_height_drawable / 3)},
    //                 {0.6, 0.5});
    //    createText("Server choice", _fonts[TITLE],
    //               {static_cast<float>(_width_drawable / 6),
    //                static_cast<float>(_height_drawable / 3.4)},
    //               {0.6, 0.5});
    //    createInput(_fonts[TITLE], _textures[BUTTON],
    //                {static_cast<float>(_width_drawable / 6),
    //                 static_cast<float>(_height_drawable / 3)},
    //                {0.6, 0.5});
    //    //    server ip
    //
    //    createSprite(_textures[BUTTON],
    //                 {static_cast<float>(_width_drawable / 5),
    //                  static_cast<float>(_height_drawable / 2.2)},
    //                 {0.8, 0.5});
    //    createText("Server ip", _fonts[TITLE],
    //               {static_cast<float>(_width_drawable / 5),
    //                static_cast<float>(_height_drawable / 2.4)},
    //               {0.8, 0.5});
    //    createInput(_fonts[TITLE], _textures[BUTTON],
    //                {static_cast<float>(_width_drawable / 5),
    //                 static_cast<float>(_height_drawable / 2.2)},
    //                {0.6, 0.5});
    //    //    //    server port
    //    createSprite(_textures[BUTTON],
    //                 {static_cast<float>(_width_drawable / 5),
    //                  static_cast<float>(_height_drawable / 1.8)},
    //                 {0.8, 0.5});
    //    createText("Server Port", _fonts[TITLE],
    //               {static_cast<float>(_width_drawable / 5),
    //                static_cast<float>(_height_drawable / 1.8)},
    //               {0.8, 0.5});
    //    //    go to lobby
    createButton(std::bind(&Game::changeState, this, GAME), "Go To lobby",
                 _textures[BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 6),
                  static_cast<float>(_height_drawable / 1.5)},
                 {0.6, 0.5});
    //    //    settings
    createButton(std::bind(&Game::changeState, this, SETTINGS), "",
                 _textures[PARAMETER_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 1.12),
                  static_cast<float>(_height_drawable / 1.05)},
                 {0.10, 0.10});
    //    //    quit
    createButton(std::bind(&Game::changeState, this, MENU), "",
                 _textures[QUIT_BUTTON], _fonts[TITLE],
                 {static_cast<float>(_width_drawable / 1.05),
                  static_cast<float>(_height_drawable / 1.05)},
                 {0.10, 0.10});
}

void Game::createRoundedButton(std::string text, sf::Font &font,
                               sf::Vector2f position, sf::Vector2f scale,
                               sf::Color colorButton, sf::Color colorText,
                               std::function<void()> _func) {
    uint32_t button_entity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::RoundedClickableData clickable_temp = {
        {position.x, position.y}, {scale.x, scale.y}, colorButton};

    Engine::RendererModule::Components::TextData text_temp = {
        text,
        font,
        colorText,
        {position.x + (scale.x / 2), position.y + (scale.y / 3)},
        {1, 1}};

    std::shared_ptr<
        Engine::RendererModule::Components::RoundedClickableComponent>
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

void Game::setParallax() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width_drawable) / textureSize.x;
    float scale_y = static_cast<float>(_height_drawable) / textureSize.y;

    float       scale = std::max(scale_x, scale_y);
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
}

void Game::InitGame() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width_drawable) / textureSize.x;
    float scale_y = static_cast<float>(_height_drawable) / textureSize.y;

    float       scale = std::max(scale_x, scale_y);
    const float myRef = {static_cast<float>(1.0)};

    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
}

void Game::GameStart() {
    std::vector<uint32_t> AllEntities = getEntities();
    for (uint32_t i = 0; i < AllEntities.size(); i++) {
        _entities =
            _gameEngine.getEntityManager()->destroyEntity(AllEntities[i]);
    }
    InitGame();
    // _gameEngine.getEntityManager()->removeComponent(getEntities(), );
}

void Game::SoundUp() { _sounds[0]->setVolume(_sounds[0]->getVolume() + 1); }

void Game::SoundLess() { _sounds[0]->setVolume(_sounds[0]->getVolume() - 1); }

void Game::WindowSize500() {
    _gameEngine.getRendererModule()->getWindow().setSize({500, 500});
}

void Game::WindowSize800() {
    _gameEngine.getRendererModule()->getWindow().setSize({800, 600});
}

void Game::WindowSizeFullscreen() {
    // TODO: Get screen size to set window size with it.
}

void Game::setSettings() {
    // SOUND SECTION.
    // Sound title.
    createText("Volume", _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 2 - 300)},
               {2, 2});
    // Text sound.
    // TODO: Find a way to retrieve the component with his id to change the
    // value of volume.
    createText(std::to_string(static_cast<int>(_sounds[0]->getVolume())),
               _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 2 - 200) + 40},
               {1, 1});
    // Button volume -.
    createRoundedButton("-", _fonts[TITLE],
                        {static_cast<float>(_width_drawable / 2 - 150),
                         static_cast<float>(_height_drawable / 2 - 200)},
                        {100, 100}, sf::Color::Red, sf::Color::White,
                        std::bind(&Game::SoundLess, this));
    // Button volume +.
    createRoundedButton("+", _fonts[TITLE],
                        {static_cast<float>(_width_drawable / 2 + 50),
                         static_cast<float>(_height_drawable / 2 - 200)},
                        {100, 100}, sf::Color::Red, sf::Color::White,
                        std::bind(&Game::SoundUp, this));

    // WINDOW_SIZE SECTION.
    // Window size title.
    createText("Window size", _fonts[TITLE],
               {static_cast<float>(_width_drawable / 2),
                static_cast<float>(_height_drawable / 2)},
               {2, 2});
    // TODO: Fix mouse position if window size changes.
    // Window 500x500.
    createRoundedButton("500x500", _fonts[TITLE],
                        {static_cast<float>(_width_drawable / 2 - 375),
                         static_cast<float>(_height_drawable / 2 + 100)},
                        {150, 100}, sf::Color::Red, sf::Color::White,
                        std::bind(&Game::WindowSize500, this));
    // Window 800x600.
    createRoundedButton("800x600", _fonts[TITLE],
                        {static_cast<float>(_width_drawable / 2 - 75),
                         static_cast<float>(_height_drawable / 2 + 100)},
                        {150, 100}, sf::Color::Red, sf::Color::White,
                        std::bind(&Game::WindowSize800, this));
    // Window fullscreen.
    createRoundedButton("Fullscreen", _fonts[TITLE],
                        {static_cast<float>(_width_drawable / 2 + 225),
                         static_cast<float>(_height_drawable / 2 + 100)},
                        {150, 100}, sf::Color::Red, sf::Color::White,
                        std::bind(&Game::WindowSizeFullscreen, this));
}

void Game::changeState(int state) {
    clearCurrentState();
    _gameState = state;
    setupState();
}

void Game::clearCurrentState() {
    for (auto entity : _entities) {
        if (entity >= 7 || _gameState == GAME) {
            std::cout << "destruction de l'entitée " << entity << std::endl;
            _gameEngine.getEntityManager()->destroyEntity(entity);
        }
    }
    _entities.erase(_entities.begin() + 7, _entities.end());
}

void Game::setupState() {
    switch (_gameState) {
        case MENU:
            setMenu();
            break;
        case LOBBY:
            //            setLobby();
            break;
        case SETTINGS:
            setSettings();
            break;
        case GAME:
            InitGame();
            break;
        default:
            break;
    }
}
