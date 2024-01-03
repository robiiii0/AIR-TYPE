#include "Client.hpp"



Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920 ? 1920 : sf::VideoMode::getDesktopMode().width;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080 ? 1080 : sf::VideoMode::getDesktopMode().height;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight, "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 0;
    _texturesParallax = LoadTextures({"src/Client/assets/assetsRefacto/Background/1.png", "src/Client/assets/assetsRefacto/Background/planet.png", "src/Client/assets/assetsRefacto/Background/planet2.png", "src/Client/assets/assetsRefacto/Background/planet3.png", "src/Client/assets/assetsRefacto/Background/Rock.png", "src/Client/assets/assetsRefacto/Background/Rock2.png", "src/Client/assets/assetsRefacto/Background/Rock3.png"});
}



void Client::setMenu()
{
    createParallax(_texturesParallax);
}


void Client::ConnectionWithServer() {
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
    setMenu();
}

void Client::run() {
    ConnectionWithServer();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
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

    }
}

// TODO : implement server response for the menu, create sprite when i have the response


int main() {
    Client client;
    client.run();
    return 0;
}
