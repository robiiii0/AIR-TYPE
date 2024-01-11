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
    playerInit();
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

    // LoadSound("src/Client/assets/Sound/music.wav", true, true, 50);
    // LoadSound("src/Client/assets/Sound/click.wav", false, false, 50);
}

void Client::ConnectionWithServer() {
    _networkingModule = std::make_unique<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
}

void Client::updateSpritePosition(
    int id, Engine::Entity::Component::GenericComponents::Vector2f pos) {
    _gameEngine.getRendererModule()->UpdatePosition(
        *_gameEngine.getEntityManager(), getEntities(), pos);
}

void Client::HandlePlayerManagement(
    Engine::Network::Serializer::entity_t &player, int place) {
    if (player.id > -1 && player.id < 4) {
        std::cout << "Player " << player.id << " at " << player.x << " "
                  << player.y << std::endl;
        if (_player[place].id == -1 && player.id != _player[0].id &&
            player.id != _player[1].id && player.id != _player[2].id &&
            player.id != _player[3].id && player.x < 1920 && player.x >= 0 &&
            player.y < 1080 && player.y >= 0) {
            _ClientId = place;
            _player[place].id = player.id;
            _player[place].x = player.x;
            _player[place].y = player.y;
            _player[place].direction = player.direction;
            createPlayer(_texturePlayer[place], {player.x, player.y});
        } else if (_player[place].id > -1 && _player[place].id < 4 &&
                   player.x <= 1920 && player.x >= 0 && player.y <= 1080 &&
                   player.y >= 0 &&
                   (player.x != _player[place].x ||
                    player.y != _player[place].y) &&
                   _player[place].id == player.id) {
            updateSpritePosition(_player[place].id, {player.x, player.y});
            _player[place].x = player.x;
            _player[place].y = player.y;
        }
    }
}

void Client::run() {
    setupState();
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        std::string eventKey =
            _hmiModule->keyEvent(_gameEngine.getRendererModule()->HandleEvent(
                *_gameEngine.getEntityManager(), getEntities()));
        HandleMovementManager(eventKey);
        if (_networkingModule != nullptr) {
            for (auto &client :
                 _networkingModule->getClients()) {  // ? client update
                while (client.getBuffer()->hasPacket()) {
                    std::string msg = client.getBuffer()->readNextPacket();
                    Engine::Network::Serializer::serialized_data_t data =
                        _networkingModule->getSerializer().binaryStringToStruct(
                            msg);
                    int place = 0;
                    for (auto &player : data.players) {
                        HandlePlayerManagement(player, place);
                        place++;
                    }
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
