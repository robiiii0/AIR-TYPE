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


Engine::RendererModule::Components::SpriteData createSprite(std::uint32_t _id, std::string  _path, std::string   _ptr, sf::Texture &_texture, sf::Sprite &_sprite, std::pair<float, float> pos)
{
    Engine::RendererModule::Components::SpriteData Sprite = {
         _id, _texture, _sprite, _path, _ptr, pos
    };
    return Sprite;
}


int main() {
    Game     game;
    uint32_t TitleEntity =
        game.getGameEngine().getEntityManager()->createEntity();

        uint32_t BackgroundEntity =
        game.getGameEngine().getEntityManager()->createEntity();
        uint32_t CakeEntity =
        game.getGameEngine().getEntityManager()->createEntity();

    sf::Font     font;
    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

    if (!font.loadFromFile("src/Client/src/Roboto-Bold.ttf")) {
        std::cout << "cant load this shit" << std::endl;
    }

    Engine::RendererModule::Components::TextData Title =
        createText("Welcome on the R-Type game", font, sf::Color::White,
                   {float(WIDTH / 8), float(HEIGHT / 8)}, {1, 1}, 0);
    
    Engine::RendererModule::Components::TextComponent titleComponent(Title);

    sf::Texture texture;
    sf::Sprite sprite;

    Engine::RendererModule::Components::SpriteData spriteBackgroundData = createSprite(BackgroundEntity, "src/Client/assets/Background/Layers/layer01_ground.png", "jsp", texture ,sprite, {float((WIDTH * 10)/ 100) *-1, float((HEIGHT * 10)/ 100) *-1});
    Engine::RendererModule::Components::SpriteComponent BackgroundComponent(spriteBackgroundData);

    Engine::RendererModule::Components::SpriteData spriteCakeData = createSprite(CakeEntity, "src/Client/assets/Background/Layers/layer02_cake.png", "jsp", texture ,sprite, {float((WIDTH * 10)/ 100) *-1, float((HEIGHT * 10)/ 100) *-1});
    Engine::RendererModule::Components::SpriteComponent CakeComponent(spriteCakeData);

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(TitleEntity),
        titleComponent);

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(BackgroundEntity),
        BackgroundComponent);

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(CakeEntity),
        CakeComponent);
    
    game.run();
    return 0;
}
