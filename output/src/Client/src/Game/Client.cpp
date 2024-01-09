#include "Client.hpp"

Client::Client() {
    _screenWidth = sf::VideoMode::getDesktopMode().width > 1920 ? 1920 : 1920;
    _screenHeight = sf::VideoMode::getDesktopMode().height > 1080 ? 1080 : 1080;
    _gameEngine.getRendererModule()->init(_screenWidth, _screenHeight,
                                          "Air Typing", 60);
    _networkingModule = nullptr;
    _hmiModule = std::make_shared<Engine::HmiModule>();
    _ClientId = 8;
    _gameState = MENU;
    LoadTextureParallax(
        "src/Client/assets/new_assets/background/Menu/earth.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/gaz.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/Menu/ice.png");
    LoadTextureButton("src/Client/assets/Buttons/Button.png");
    LoadTextureButton(
        "src/Client/assets/assetsRefacto/settings/emptyButton.png");
    LoadFont("src/Client/assets/Fonts/Roboto-Bold.ttf");
    LoadTextureBoss("src/Client/assets/new_assets/enemy/sprites/boss.png");
    LoadTexturePlayer(
        "src/Client/assets/new_assets/player/sprites/player1_pink.png");
    LoadTexturePlayer(
        "src/Client/assets/new_assets/player/sprites/player1_red.png");
    LoadTexturePlayer(
        "src/Client/assets/new_assets/player/sprites/player1_yellow.png");
    LoadTexturePlayer(
        "src/Client/assets/new_assets/player/sprites/player1.png");

    LoadSettingsKeyBindings("src/Client/assets/assetsRefacto/settings/Up.png");
    LoadSettingsKeyBindings(
        "src/Client/assets/assetsRefacto/settings/key_left.png");
    LoadSettingsKeyBindings(
        "src/Client/assets/assetsRefacto/settings/key_Down.png");
    LoadSettingsKeyBindings(
        "src/Client/assets/assetsRefacto/settings/key_right.png");
    LoadSettingsKeyBindings(
        "src/Client/assets/assetsRefacto/settings/Space.png");

    LoadTextureMissile("src/Client/assets/new_assets/shoot/shoot1.png");
    LoadTextureEnemies("src/Client/assets/new_assets/enemy/sprites/enemy5.png");

    LoadSound("src/Client/assets/Sound/music.wav", true, true, 50);
    LoadSound("src/Client/assets/Sound/click.wav", false, false, 50);
}

void Client::CommandManagerForPlayer(
    Engine::Network::Serializer::serialized_data_t data) {
    // todo faire une boucle pour checker tout les players

    int size = _player.size();
    int taille = 0;
    for (auto &player : data.players) {
        if (player.id > -1 && player.id < 4) {
            if (size <= player.id) {
                std::cout << _player.size() << "and " <<  player.id << "at :" << player.x  <<" " <<player.y << std::endl;
                taille++;
                createPlayer(_texturePlayer[player.id], { static_cast<float>(20 + (player.id * 200)),  static_cast<float>(20 + (player.id * 200))});
                _player.push_back(player);
            }
        }
    }
    if (taille > 0)
        std::cout << "la taille est de " << taille << std::endl;
}

void Client::GetClientId(Engine::Network::Serializer::serialized_data_t data) {
    for (auto &player : data.players) {
        if (player.id > -1) {
            _ClientId = player.id;
        }
    }
}

void Client::ConnectionWithServer() {
    _networkingModule = std::make_unique<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);

    for (auto &client :
        _networkingModule->getClients()) {  // ? client update
        while (client.getBuffer()->hasPacket()) {
            std::string msg = client.getBuffer()->readNextPacket();
            Engine::Network::Serializer::serialized_data_t data =
                _networkingModule->getSerializer().binaryStringToStruct(
                    msg);
            GetClientId(data);
        }
    }
}

void Client::run() {
    setupState();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        std::string eventKey = _hmiModule->keyEvent(
            _gameEngine.getRendererModule()->UpdateForServer(
                *_gameEngine.getEntityManager(), getEntities()));
        if (eventKey == "exit") {
            _networkingModule->~NetworkingModule();
            _gameEngine.getRendererModule()->getWindow().close();
        }
        if (_networkingModule != nullptr) {
            for (auto &client :
                 _networkingModule->getClients()) {  // ? client update
                while (client.getBuffer()->hasPacket()) {
                    std::string msg = client.getBuffer()->readNextPacket();
                    Engine::Network::Serializer::serialized_data_t data =
                        _networkingModule->getSerializer().binaryStringToStruct(
                            msg);
                    CommandManagerForPlayer(data);
                }
            }
        }
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
    }
    handleExit();
}

// TODO : implement server response for the menu, create sprite when i have the
// response
