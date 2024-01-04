#include "../Client.hpp"

void Client::setSetting()
{
    int nb = 0;
    createBackground(_backgroundTexture);
    createParallax(_texturesParallax);
    createButton([this]() {}, "Change Key", _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x, _screenHeight / 2 - _texturesButton[0].getSize().y / nb),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    nb++;
    createButton([this]() {}, "Setting", _texturesButton[0], _fonts[0],
                 sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x, _screenHeight / 2 - _texturesButton[0].getSize().y / nb),
                 sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    nb++;
    
}