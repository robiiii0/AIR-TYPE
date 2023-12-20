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

Engine::RendererModule::Components::TextData createText(
    std::string text, sf::Font &font, sf::Color color, sf::Vector2f position,
    sf::Vector2f scale, float rotation) {
    Engine::RendererModule::Components::TextData textData1 = {
        text, font, color, position, scale, rotation};
    return textData1;
}

void Game::displaySettings() {
    // ###################### DEFAULT FOR ALL SCREENS. ######################
    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

    if (!_font.loadFromFile(std::string("src/Client/src/Roboto-Bold.ttf")))
        std::cout << "Error loading font" << std::endl;
    // ######################################################################

    // Entity creation.
    uint32_t SoundVolumeEntity =
            _gameEngine.getEntityManager()->createEntity();

    // Data creation.
    Engine::RendererModule::Components::TextData SoundVolumeData =
        createText("100", _font, sf::Color::White,
                   {float(WIDTH / 6), float(HEIGHT / 14)}, {1, 1}, 0);

    // Component creation.
    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        SoundVolumeComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                SoundVolumeData);

    // Component addition.
    _gameEngine.getEntityManager()->addComponent(SoundVolumeEntity,
                                                          SoundVolumeComponent);

    // Entity addition.
    addEntity(SoundVolumeEntity);
}
