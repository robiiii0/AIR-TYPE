/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** main
*/

#include "../../GameEngine/GameEngine.hpp"
#include "./Game/Game.hpp"

Engine::RendererModule::Components::TextData createText(
    std::string text, sf::Font &font, sf::Color color, sf::Vector2f position,
    sf::Vector2f scale, float rotation) {
    Engine::RendererModule::Components::TextData textData1 = {
        text, font, color, position, scale, rotation};
    return textData1;
}

Engine::RendererModule::Components::SpritData createSprite(
                    sf::Texture _texture, sf::Sprite _sprite, std::uint32_t _id, std::string   _path, std::string   _ptr) {
                            Engine::RendererModule::Components::SpritData Sprite = {
        _texture, _sprite, _id, _path, _ptr
    };
    return Sprite;
                    }





int main() {
    Game     game;
    uint32_t TitleEntity =
        game.getGameEngine().getEntityManager()->createEntity();

        uint32_t BackgroundEntity =
        game.getGameEngine().getEntityManager()->createEntity();

    sf::Font     font;
    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

    if (!font.loadFromFile("src/Client/src/Roboto-Bold.ttf")) {
        std::cout << "cant load this shit" << std::endl;
    }

    Engine::RendererModule::Components::TextData Title =
        createText("Welcome on the R-Type game", font, sf::Color::White,
                   {float(WIDTH / 4), float(HEIGHT / 4)}, {1, 1}, 0);
    
    Engine::RendererModule::Components::TextComponent titleComponent(Title);

    sf::Texture texture;

    sf::Sprite sprite;

    Engine::RendererModule::Components::SpritData spriteBackgroundData = createSprite(texture ,sprite,  BackgroundEntity, "src/Client/assets/Background/Layers/layer01_ground.png", "jsp");
    Engine::RendererModule::Components::SpriteComponent BackgroundComponent(spriteBackgroundData);

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(TitleEntity),
        titleComponent);

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(BackgroundEntity),
        BackgroundComponent);
    
    game.run();
    return 0;
}
