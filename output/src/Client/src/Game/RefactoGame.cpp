#include "RefactoGame.hpp"


std::vector<sf::Texture> Client::LoadTextures(std::vector<std::string> paths) {
    std::vector<sf::Texture> textures;

    for (auto path : paths) {
        sf::Texture texture;
        if (texture.loadFromFile(path) == false) {
            std::cerr << "Error: could not load texture " << path << std::endl;
            exit(84);
        }
        textures.push_back(texture);
    }
    return textures;
}

Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920 ? 1920 : sf::VideoMode::getDesktopMode().width;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080 ? 1080 : sf::VideoMode::getDesktopMode().height;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight, "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 0;
    _texturesParallax = LoadTextures({"src/Client/assets/assetsRefacto/Background/1.png", "src/Client/assets/assetsRefacto/Background/planet.png", "src/Client/assets/assetsRefacto/Background/planet2.png", "src/Client/assets/assetsRefacto/Background/planet3.png", "src/Client/assets/assetsRefacto/Background/Rock.png", "src/Client/assets/assetsRefacto/Background/Rock2.png", "src/Client/assets/assetsRefacto/Background/Rock3.png"});
}


void Client::createParallax()
{

}


void Client::setMenu()
{
    createParallax();
}


std::vector<std::uint32_t> &Client::getEntities() { return _entities; }


void Client::ConnectionWithServer() {
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
    _networkingModule->sendMessage("Asking for menu", 0);
}

void Client::run() {
    ConnectionWithServer();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        std::string eventKey = _hmiModule->keyEvent(
            _gameEngine.getRendererModule()->UpdateForServer(
                *_gameEngine.getEntityManager(), getEntities()));

    }
}

// TODO : implement server response for the menu, create sprite when i have the response


int main() {
    Client client;
    client.run();
    return 0;
}
