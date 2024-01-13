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
    int id, Engine::Entity::Component::GenericComponents::Vector2f pos,
    uint32_t id_sprite) {
    _gameEngine.getRendererModule()->UpdatePosition(
        *_gameEngine.getEntityManager(), getEntities(), pos, id_sprite);
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
            std::cout << "Player created" << _player[place].id << " at "
                      << _player[place].x << " " << _player[place].y
                      << std::endl;
            uint32_t id_sprite =
                createPlayer(_texturePlayer[place], {player.x, player.y});

            std::cout << "'id de player =" << id_sprite << std::endl;
            _player[place].idSprite = id_sprite;
        } else if (_player[place].id > -1 && _player[place].id < 4 &&
                   player.x <= 1920 && player.x >= 0 && player.y <= 1080 &&
                   player.y >= 0 &&
                   (player.x != _player[place].x ||
                    player.y != _player[place].y) &&
                   _player[place].id == player.id) {
            std::cout << "oe chef" << std::endl;
            updateSpritePosition(_player[place].id, {player.x, player.y},
                                 _player[place].idSprite);
            std::cout << "new pos for " << player.id << " " << player.x << " "
                      << player.y << std::endl;
            _player[place].x = player.x;
            _player[place].y = player.y;
        }
    }
}

void Client::HandleMissileManager(
    Engine::Network::Serializer::entity_t &missile, int place) {
    std::cout << "Missile " << missile.id << " at " << missile.x << " "
              << missile.y << std::endl;

    if (missile.id > -1 && missile.id < MAX_MISSILES) {
        std::cout << "missile " << missile.id << " at " << missile.x << " "
                  << missile.y << std::endl;
        if (_missile[place].id == -1 && missile.id != _missile[0].id &&
            missile.x < 1920 && missile.x >= 0 && missile.y < 1080 &&
            missile.y >= 0) {
            _missile[place].id = missile.id;
            _missile[place].x = missile.x;
            _missile[place].y = missile.y;
            _missile[place].direction = missile.direction;
            uint32_t idMissile = createMissile(
                _missile[place].id, _missile[place].x, _missile[place].y);
            std::cout << "'id de missile =" << idMissile << std::endl;
            _missile[place].idSprite = idMissile;
        } else if (_missile[place].id > -1 &&
                   _missile[place].id < MAX_MISSILES && missile.x <= 1920 &&
                   missile.x >= 0 && missile.y <= 1080 && missile.y >= 0 &&
                   (missile.x != _missile[place].x ||
                    missile.y != _missile[place].y) &&
                   _missile[place].id == missile.id) {
            std::cout << "je suis dedans" << std::endl;
            updateSpritePosition(_missile[place].id, {missile.x, missile.y},
                                 _missile[place].idSprite);
            _missile[place].x = missile.x;
            _missile[place].y = missile.y;
        }
    }
    // createmissile(_texturemissile[place], {missile.x, missile.y});
}

void Client::HandleEnemiesManagement(
    Engine::Network::Serializer::entity_t &enemy, int place) {
    if (enemy.id > -1 && enemy.id < MAX_ENEMIES) {
        std::cout << "enemy " << enemy.id << " at " << enemy.x << " " << enemy.y
                  << std::endl;
        if (_enemy[place].id == -1 && enemy.id != _enemy[0].id &&
            enemy.x < 1920 && enemy.x >= 0 && enemy.y < 1080 && enemy.y >= 0) {
            _enemy[place].id = enemy.id;
            _enemy[place].x = enemy.x;
            _enemy[place].y = enemy.y;
            _enemy[place].direction = enemy.direction;
            uint32_t idEnemy =
                createPlayer(_texturesEnemies[0], {enemy.x, enemy.y});
            std::cout << "'id de enemy =" << idEnemy << std::endl;
            _enemy[place].idSprite = idEnemy;
        } else if (_enemy[place].id > -1 && _enemy[place].id < MAX_ENEMIES &&
                   enemy.x <= 1920 && enemy.x >= 0 && enemy.y <= 1080 &&
                   enemy.y >= 0 &&
                   (enemy.x != _enemy[place].x || enemy.y != _enemy[place].y) &&
                   _enemy[place].id == enemy.id) {
            std::cout << "je suis dedans" << std::endl;
            updateSpritePosition(_enemy[place].id, {enemy.x, enemy.y},
                                 _enemy[place].idSprite);
            _enemy[place].x = enemy.x;
            _enemy[place].y = enemy.y;
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
                    int placePlayer = 0;
                    int placeMissiles = 0;
                    int placeEnemies = 0;
                    for (auto &player : data.players) {
                        HandlePlayerManagement(player, placePlayer);
                        placePlayer++;
                    }
                    for (auto &missile : data.missiles) {
                        HandleMissileManager(missile, placeMissiles);
                        placeMissiles++;
                    }
                    for (auto &enemy : data.enemies) {
                        HandleEnemiesManagement(enemy, placeEnemies);
                        placeEnemies++;
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
