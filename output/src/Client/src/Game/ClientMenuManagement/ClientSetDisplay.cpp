#include "../Client.hpp"

void Client::setMenu() {
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createButton([this]() { std::cout << "click" << std::endl; }, "Play",
                 _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2, _screenHeight / 2),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
}
