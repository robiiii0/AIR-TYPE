#include "../Client.hpp"

void Client::setMenu() {
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createButton(std::bind(&Client::changeState, this, GameState::GAME), "Play",
                 _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2, _screenHeight / 2),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
}

void Client::setGame() {
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createPlayer(_texturePlayer);
    createButton(std::bind(&Client::changeState, this, MENU), "",
                 _texturesButton[0], _fonts[0],
                 {static_cast<float>(_screenWidth / 1.05),
                  static_cast<float>(_screenHeight / 1.05)},
                 {0.10, 0.10}, sf::Color::White, 0);
}
