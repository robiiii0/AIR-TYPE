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
}

void Game::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update();
        std::cout << "CACA" << std::endl;
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

void Game::setLobby() {
    sf::Vector2u textureSize = _textures[0].getSize();

    float scale_x = static_cast<float>(_width) / textureSize.x;
    float scale_y = static_cast<float>(_height) / textureSize.y;
    float scale = std::min(scale_x, scale_y);
    createSprite(_textures[0], {0.0, 0.0}, {scale, scale});
    createSprite(_textures[1], {00.0, 400.0}, {0.5, 0.5});
    createText("Welcome on the R-Type game", _fonts[TITLE], {200.0, 200.0});
}

void Game::setHomepage() {
    uint32_t TitleEntity = _gameEngine.getEntityManager()->createEntity();
    uint32_t StartButtonEntity = _gameEngine.getEntityManager()->createEntity();

    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;
x
    if (!_font.loadFromFile("src/Client/src/Roboto-Bold.ttf")) {
        std::cout << "cant load this shit" << std::endl;
    }

    sf::Texture texture;
    sf::Sprite  sprite;

    if (!texture.loadFromFile("src/Client/assets/Buttons/start.png"))
        throw std::runtime_error("SpriteComponent: texture not found");
    sprite.setTexture(texture);

    Engine::RendererModule::Components::ClickableData Clickable = {
        false,      false,
        texture,    sprite,
        "Stop",     "src/Client/assets/Buttons/start.png",
        "jsp",      {float((WIDTH * 20) / 100), float((HEIGHT * 8) / 100)},
        {0.5, 0.5}, StartButtonEntity};

    std::shared_ptr<Engine::RendererModule::Components::ClickableComponent>
        ClickableStart = std::make_shared<
            Engine::RendererModule::Components::ClickableComponent>(Clickable);

    Engine::RendererModule::Components::TextData Title =
        createText("Welcome on the R-Type game", _font, sf::Color::White,
                   {float(WIDTH / 6), float(HEIGHT / 14)}, {1, 1}, 0);

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        titleComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                Title);

    _gameEngine.getEntityManager()->addComponent(TitleEntity, titleComponent);
    _gameEngine.getEntityManager()->addComponent(StartButtonEntity,
                                                 ClickableStart);

    addEntity(TitleEntity);
    addEntity(StartButtonEntity);
}
