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
    LoadTextureParallax(
        "src/Client/assets/new_assets/background/Menu/earth.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/gaz.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/ice.png");
    LoadTextureButton("src/Client/assets/Buttons/Button.png");
    LoadFont("src/Client/assets/Fonts/Roboto-Bold.ttf");
    LoadBackground();
    // addPlayer();
    LoadTexturePlayer(
        "src/Client/assets/new_assets/player/sprites/player1_pink.png");
    // addPlayer();x
}

void Client::ConnectionWithServer() {
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
}

void Client::run() {
    ConnectionWithServer();
    setMenu();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        // std::chrono::high_resolution_clock::time_point clock =
        //     std::chrono::high_resolution_clock::now();
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
                    // std::cout << "Message received: " << msg << std::endl;
                    auto data =
                        _networkingModule->getSerializer().binaryStringToStruct(
                            msg);
                    std::cout << "To Add Players:" << data.to_add.nb_players
                              << std::endl;
                    // for (int i = 0; i < data.to_add.nb_players; ++i) {
                    //     std::cout << "Player ID: " <<
                    //     data.to_add.players[i].id
                    //             << ", X: " << data.to_add.players[i].x
                    //             << ", Y: " << data.to_add.players[i].y <<
                    //             std::endl;
                    // }

                    // Printing information from the 'to_add' game_objects_t
                    // std::cout << "To Add Missiles:" << std::endl;
                    // for (int i = 0; i < data.to_add.nb_missiles; ++i) {
                    //     std::cout << "Missile ID: " <<
                    //     data.to_add.missiles[i].id
                    //             << ", X: " << data.to_add.missiles[i].x <<
                    //             std::endl;
                    // }
                }
            }
        }
        // const auto elapsed =
        //     std::chrono::duration_cast<std::chrono::microseconds>(
        //         std::chrono::high_resolution_clock::now() - clock);
        // if (elapsed.count() < 1000 / 16) {
        //     const long duration = 1000000 / 16;
        //     const long sleepTime = duration - elapsed.count();
        //     if (sleepTime > 0) {
        //         std::this_thread::sleep_for(
        //             std::chrono::microseconds(sleepTime));
        //     }
        // }
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
}

// TODO : implement server response for the menu, create sprite when i have the
// response
