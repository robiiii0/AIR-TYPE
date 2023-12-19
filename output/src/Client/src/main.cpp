/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** main
*/

#include "../../GameEngine/GameEngine.hpp"
#include "./Game/Game.hpp"

int main() {
    Game     game;
    uint32_t text1 = game.getGameEngine().getEntityManager()->createEntity();
    sf::Font font;
    font.loadFromFile("../assets/Fonts/Roboto-Medium.ttf");
    Engine::RendererModule::Components::TextData textData1 = {
        "Hello World", font, sf::Color::White, {0, 0}, {1, 1}, 0};
    Engine::RendererModule::Components::TextComponent textComponent1(textData1);
    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(text1),
        textComponent1);
    game.run();
    return 0;
}
