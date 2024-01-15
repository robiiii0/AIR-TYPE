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
    LoadBackground();
    loadTextureEnd("src/Client/assets/Background/Top_1.png");
    loadTextureEnd("src/Client/assets/Background/Game_Over_logo.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/1.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/2.png");
    LoadTextureParallax("src/Client/assets/new_assets/background/3.png");
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

    LoadSound("src/Client/assets/Sound/music.wav", true, false, 50);
    LoadSound("src/Client/assets/Sound/click.wav", false, false, 50);
    LoadSound("src/Client/assets/new_assets/shoot/shot.mp3", false, false, 50);
    LoadSound("src/Client/assets/new_assets/shoot/Bloopin.mp3", false, false,
              50);
    LoadSound("src/Client/assets/new_assets/shoot/Sadsongmeme.mp3", false,
              false, 50);
}

void Client::ConnectionWithServer() {
    _networkingModule = std::make_shared<Engine::Network::NetworkingModule>(
        0, Engine::Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242, 10);
    _networkingModule->sendMessage("Connecting to server", 0);
}

void Client::updateSpritePosition(
    int id, Engine::Entity::Component::GenericComponents::Vector2f pos,
    uint32_t id_sprite) {
    _gameEngine.getRendererModule()->UpdatePosition(
        *_gameEngine.getEntityManager(), getEntities(), pos, id_sprite);
}

void Client::HandlePlayerManagement(
    Engine::Network::Serializer::entity_t &player, int place) {
    if (player.id > -1) {
        if (player.x < 1920 && player.x > 0 && player.y < 1080 &&
            player.y > 30) {
            uint32_t id_sprite =
                createPlayer(_texturePlayer[place], {player.x, player.y});
            _destructible_entities.push_back(id_sprite);
        }
    }
}

void Client::HandleMissileManager(
    Engine::Network::Serializer::entity_t &missile, int place) {
    if (missile.id > -1 && missile.id < MAX_MISSILES) {
        if (missile.x < 1920 && missile.x > 0 && missile.y < 1080 &&
            missile.y > 30) {
            uint32_t idMissile =
                createMissile(missile.id, missile.x, missile.y);
            _destructible_entities.push_back(idMissile);
        }
    }
}

void Client::HandleEnemiesManagement(
    Engine::Network::Serializer::entity_t &enemy, int place) {
    if (enemy.id > -1 && enemy.id < MAX_ENEMIES) {
        if (enemy.x < 1920 && enemy.x > 0 && enemy.y < 1080 && enemy.y > 30) {
            uint32_t idEnemy =
                createPlayer(_texturesEnemies[0], {enemy.x, enemy.y});
            _destructible_entities.push_back(idEnemy);
        }
    }
}

void Client::run() {
    while (_gameEngine.getRendererModule()->getWindow().isOpen()) {
        std::cout << "test 6" << std::endl;

        if (_networkingModule != nullptr) {
            std::cout << "test 7" << std::endl;

            for (auto &client :
                 _networkingModule->getClients()) {  // ? client update
                if (client.getBuffer()->hasPacket()) {
                    std::string msg = client.getBuffer()->readNextPacket();
                    Engine::Network::Serializer::serialized_data_t data =
                        _networkingModule->getSerializer().binaryStringToStruct(
                            msg);
                    for (auto &player : data.players) {
                        HandlePlayerManagement(player, 0);
                    }
                    for (auto &missile : data.missiles) {
                        HandleMissileManager(missile, 0);
                    }
                    for (auto &enemy : data.enemies) {
                        HandleEnemiesManagement(enemy, 0);
                    }
                }
            }
        }
        _gameEngine.getRendererModule()->update(*_gameEngine.getEntityManager(),
                                                getEntities());
        std::string eventKey =
            _hmiModule->keyEvent(_gameEngine.getRendererModule()->HandleEvent(
                *_gameEngine.getEntityManager(), getEntities()));
        HandleMovementManager(eventKey);
        _gameEngine.getRendererModule()->render(*_gameEngine.getEntityManager(),
                                                getEntities());
        for (int i = _destructible_entities.size(); i > 0; i--) {
            _gameEngine.getEntityManager()->destroyEntity(
                _destructible_entities.back());
            _entities.erase(std::remove(_entities.begin(), _entities.end(),
                                        _destructible_entities.back()),
                            _entities.end());
            _destructible_entities.pop_back();
        }
        std::cout << "test" << std::endl;
    }
    handleExit();
}

// TODO : implement server response for the menu, create sprite when i have the
// response
