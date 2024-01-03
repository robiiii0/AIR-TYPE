#include "Client.hpp"



Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920 ? 1920 : sf::VideoMode::getDesktopMode().width;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080 ? 1080 : sf::VideoMode::getDesktopMode().height;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight, "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 0;
    LoadBackground();
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/earth.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/gaz.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/ice.png");
    LoadTexturePlayer("src/Client/assets/new_assets/player/sprites/player1_pink.png");
    // addPlayer();x
}


void Client::setMenu()
{
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createPlayer(_texturePlayer);
    
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
