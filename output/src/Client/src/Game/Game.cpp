//
// Created by Kl Eddie on 29/11/2023.
//

#include "Game.hpp"

Game::Game() {
    _gameEngine.getRendererModule()->init(
        int(sf::VideoMode::getDesktopMode().width),
        int(sf::VideoMode::getDesktopMode().height), "Air-Type", 60);
    if (!_font.loadFromFile("src/Client/src/Roboto-Bold.ttf")) {
        std::cout << "cant load this shit" << std::endl;
    }
    if (!_texture.loadFromFile("src/Client/assets/Background/Layers/layer02_cake.png")) {
        std::cout << "cant load" << std::endl;
    }
    _sprite.setTexture(_texture);
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

void Game::createSprite(sf::Sprite sprite, sf::Texture &texture,
                        sf::Vector2f position, sf::Vector2f scale,
                        sf::Color color, float rotation) {
    uint32_t spriteEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::SpriteData sprite_temp = {
        sprite, position, scale, color, rotation};

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent;
    spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 texture);

    _gameEngine.getEntityManager()->addComponent(spriteEntity, spriteComponent);
    addEntity(spriteEntity);
}

void Game::setLobby() {
    createText("Welcome on the R-Type game", _font, {200.0, 200.0});
    createSprite(_sprite, _texture, {200.0, 200.0});
    //    uint32_t CakeEntity =
    //        game.getGameEngine().getEntityManager()->createEntity();

    //    sf::Texture texture;
    //    sf::Sprite  sprite;

    //    Engine::RendererModule::Components::SpriteData spriteCakeData =
    //        createSprite(
    //            CakeEntity,
    //            "src/Client/assets/Background/Layers/layer02_cake.png", "jsp",
    //            texture, sprite, {float((WIDTH * 10) / 100) * -1,
    //            float((HEIGHT * 10) / 100) * -1});
    //
    //    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
    //    // CakeComponent;
    //    auto CakeComponent =
    //        std::make_shared<Engine::RendererModule::Components::SpriteComponent>(
    //            spriteCakeData);

    //    game.getGameEngine().getEntityManager()->addComponent(CakeEntity,
    //                                                          CakeComponent);
    //    game.addEntity(CakeEntity);
}
