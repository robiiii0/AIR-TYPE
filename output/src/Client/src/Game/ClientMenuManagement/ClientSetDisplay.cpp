#include "../Client.hpp"

void Client::setMenu() {
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createButton(std::bind(&Client::changeState, this, GameState::GAME), "Play",
                 _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2, _screenHeight / 2),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    createButton(std::bind(&Client::changeState, this, GameState::SETTINGS),
                 "Setting", _texturesButton[0], _fonts[0],
                 {static_cast<float>(_screenWidth / 2),
                  static_cast<float>(_screenHeight / 2 + 100)},
                 {0.50, 0.50}, sf::Color::White, 0);
}

void Client::setGame() {
    std::cout << "on passe au game" << std::endl;
    for (auto entities : _entities) {
        _gameEngine.getEntityManager()->destroyEntity(
                entities);

    }
    _entities.clear();
    ConnectionWithServer();
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    // createButton(std::bind(&Client::changeState, this, MENU), "",
    //              _texturesButton[0], _fonts[0],
    //              {static_cast<float>(_screenWidth / 1.05),
    //               static_cast<float>(_screenHeight / 1.05)},
    //              {0.10, 0.10}, sf::Color::White, 0);
}

void Client::ChangeKeyBinding() {
    createBackground(_backgroundTexture);
    CreateSprite({450, 250}, {0.3, 0.3}, _textureSetting[UP_TEXTURE], "Key Up");
    CreateSprite({250, 450}, {0.3, 0.3}, _textureSetting[LEFT_TEXTURE],
                 "Key Left");
    CreateSprite({450, 450}, {0.3, 0.3}, _textureSetting[DOWN_TEXTURE],
                 "Key Down");
    CreateSprite({650, 450}, {0.3, 0.3}, _textureSetting[RIGHT_TEXTURE],
                 "Key Right");
    CreateSprite({850, 250}, {0.3, 0.3}, _textureSetting[ATTACK_TEXTURE],
                 "Attack");

    createButton(std::bind(&Client::changeState, this, GameState::SETTINGS),
                 "Back", _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x,
                              _screenHeight / 1.5),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
}

void Client::setSettings() {
    // call this function to change key
    // ChangeKeyBinding();
    int nb = 0;
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createButton(
        std::bind(&Client::changeState, this, GameState::KEYBINDING),
        "Change Key", _texturesButton[0], _fonts[0],
        sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x,
                     _screenHeight / 2 - _texturesButton[0].getSize().y / nb),
        sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    nb++;
    createButton(
        std::bind(&Client::changeState, this, GameState::MENU), "Menu",
        _texturesButton[0], _fonts[0],
        sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x,
                     _screenHeight / 2 - _texturesButton[0].getSize().y / nb),
        sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    nb++;

    createText("Volume", _fonts[0],
               {static_cast<float>(_screenWidth / 2 + 100),
                static_cast<float>(_screenHeight / 3 - 50)},
               {1, 1}, sf::Color::White, 0);
    // value of volume.
    createText("100", _fonts[0],
               {static_cast<float>(_screenWidth / 2 + 100),
                static_cast<float>(_screenHeight / 3)},
               {0.5, 0.5}, sf::Color::White, 0);
    // Button volume -.

    createButton(
        [this]() {
            for (auto& soundComponent : _sounds) {
                if (soundComponent) {
                    float newVolume = soundComponent->getVolume() - 10.0f;
                    soundComponent->setVolume(newVolume);
                }
            }
        },
        "-", _texturesButton[1], _fonts[0],
        {static_cast<float>(_screenWidth / 2 - 50),
         static_cast<float>(_screenHeight / 3)},
        {0.2, 0.2}, sf::Color::White, 0);
    // Button volume +.
    createButton(
        [this]() {
            for (auto& soundComponent : _sounds) {
                if (soundComponent) {
                    float newVolume = soundComponent->getVolume() + 10.0f;
                    soundComponent->setVolume(newVolume);
                }
            }
        },
        "+", _texturesButton[1], _fonts[0],
        {static_cast<float>(_screenWidth / 2 + 250),
         static_cast<float>(_screenHeight / 3)},
        {0.2, 0.2}, sf::Color::White, 0);
    // Button return.
    createButton(std::bind(&Client::changeState, this, MENU), "",
                 _texturesButton[0], _fonts[0],
                 {static_cast<float>(_screenWidth / 1.05),
                  static_cast<float>(_screenHeight / 1.05)},
                 {0.10, 0.10}, sf::Color::White, 0);
}
