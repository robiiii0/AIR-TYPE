#include "Client.hpp"

Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920
                       ? 1920
                       : sf::VideoMode::getDesktopMode().width;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080
                        ? 1080
                        : sf::VideoMode::getDesktopMode().height;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight,
                                          "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 0;
    std::cout << "test" << std::endl;
    LoadTexture("src/Client/assets/new_assets/background/Menu/background.png");
    LoadTexture("src/Client/assets/new_assets/background/Menu/earth.png");
    LoadTextureButton("src/Client/assets/Buttons/Button.png");
    LoadFont("src/Client/assets/Fonts/Roboto-Bold.ttf");

    // LoadTexture("src/Client/assets/new_assets/back");
    std::cout << "test 3" << std::endl;
    // , "src/Client/assets/assetsRefacto/Background/planet.png",
    // "src/Client/assets/assetsRefacto/Background/planet2.png",
    // "src/Client/assets/assetsRefacto/Background/planet3.png",
    // "src/Client/assets/assetsRefacto/Background/Rock.png",
    // "src/Client/assets/assetsRefacto/Background/Rock2.png",
    // "src/Client/assets/assetsRefacto/Background/Rock3.png"
}

void Client::setMenu() {
    createParallax(_texturesParallax);
    createButton([this]() {}, "Play", _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2, _screenHeight / 2),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
}

void Client::ConnectionWithServer() {
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
}

void Client::run() {
    // ConnectionWithServer();
    setMenu();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());

        std::string eventKey = _hmiModule->keyEvent(
            _gameEngine.getRendererModule()->UpdateForServer(
                *_gameEngine.getEntityManager(), getEntities()));

        if (_networkingModule != nullptr) {
            for (auto &client :
                 _networkingModule->getClients()) {  // ? client update
                while (client.getBuffer()->hasPacket()) {
                    std::string msg = client.getBuffer()->readNextPacket();
                    std::cout << msg << std::endl;
                }
            }
        }
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
}

void Client::LoadTexture(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesParallax.push_back(texture);
}

void Client::LoadTextureButton(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesButton.push_back(texture);
}

void Client::LoadFont(std::string paths) {
    sf::Font font;
    if (font.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load font " << paths << std::endl;
        exit(84);
    }
    _fonts.push_back(font);
}

void Client::createButton(std::function<void()> func, std::string text,
                          sf::Texture &texture, sf::Font &font,
                          sf::Vector2f position, sf::Vector2f scale,
                          sf::Color color, float rotation) {
    uint32_t   entity = _gameEngine.getEntityManager()->createEntity();
    sf::Sprite tmp_sprite(texture);

    Engine::RendererModule::Components::ClickableData tmp_clickable = {
        tmp_sprite, position, scale, color, rotation};

    std::shared_ptr<Engine::RendererModule::Components::ClickableComponent>
        clickableComponent = std::make_shared<
            Engine::RendererModule::Components::ClickableComponent>(
            tmp_clickable, texture, func);

    _gameEngine.getEntityManager()->addComponent(entity, clickableComponent);

    addEntity(entity);
}

// TODO : implement server response for the menu, create sprite when i have the
// response

int main() {
    Client client;
    client.run();
    return 0;
}
