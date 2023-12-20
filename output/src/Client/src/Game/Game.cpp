//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _gameEngine.getRendererModule()->init(
        int(sf::VideoMode::getDesktopMode().width),
        int(sf::VideoMode::getDesktopMode().height), "Air-Type", 60);
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

Engine::RendererModule::Components::TextData createText(
    std::string text, sf::Font &font, sf::Color color, sf::Vector2f position,
    sf::Vector2f scale, float rotation) {
    Engine::RendererModule::Components::TextData textData1 = {
        text, font, color, position, scale, rotation};
    return textData1;
}

void Game::setLobby() {
    uint32_t TitleEntity = _gameEngine.getEntityManager()->createEntity();

    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

    if (!_font.loadFromFile("src/Client/src/Roboto-Bold.ttf")) {
        std::cout << "cant load this shit" << std::endl;
    }

    Engine::RendererModule::Components::TextData Title =
        createText("Welcome on the R-Type game", _font, sf::Color::White,
                   {float(WIDTH / 6), float(HEIGHT / 14)}, {1, 1}, 0);

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        titleComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                Title);

    _gameEngine.getEntityManager()->addComponent(TitleEntity, titleComponent);
    addEntity(TitleEntity);
}

void Game::setHomepage() {
    uint32_t TitleEntity = _gameEngine.getEntityManager()->createEntity();
    uint32_t StartButtonEntity = _gameEngine.getEntityManager()->createEntity();

    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

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
