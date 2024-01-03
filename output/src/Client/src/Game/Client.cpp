#include "Client.hpp"



Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920 ? 1920 : sf::VideoMode::getDesktopMode().width;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080 ? 1080 : sf::VideoMode::getDesktopMode().height;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight, "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 0;
    std::cout << "test" << std::endl;
    // LoadTextureParallax("src/Client/assets/new_assets/background/Menu/background.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/earth.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/gaz.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/ice.png");
    LoadBackground();
    addPlayer();

    // LoadTexture("src/Client/assets/new_assets/back");
    std::cout << "test 3" << std::endl;
    // , "src/Client/assets/assetsRefacto/Background/planet.png", "src/Client/assets/assetsRefacto/Background/planet2.png", "src/Client/assets/assetsRefacto/Background/planet3.png", "src/Client/assets/assetsRefacto/Background/Rock.png", "src/Client/assets/assetsRefacto/Background/Rock2.png", "src/Client/assets/assetsRefacto/Background/Rock3.png"

}

void Client::addPlayer()
{
    std::cout << "Create Player" << std::endl;
}

void Client::LoadTextureParallax(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesParallax.push_back(texture);
}

void Client::LoadBackground()
{
    sf::Texture texture;
    if (texture.loadFromFile("src/Client/assets/new_assets/background/Menu/background.png") == false) {
        std::cerr << "Error: could not load texture " << "src/Client/assets/new_assets/background/Menu/background.png" << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _backgroundTexture = texture;
}

void Client::setMenu()
{
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
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

// TODO : implement server response for the menu, create sprite when i have the response

int main() {
    Client client;
    client.run();
    return 0;
}
