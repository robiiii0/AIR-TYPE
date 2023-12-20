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

Engine::RendererModule::Components::SpriteData createSprite(
    std::uint32_t _id, std::string _path, std::string _ptr,
    sf::Texture &_texture, sf::Sprite &_sprite, std::pair<float, float> pos) {
    Engine::RendererModule::Components::SpriteData Sprite = {
        _id, _texture, _sprite, _path, _ptr, pos};
    return Sprite;
}

Engine::RendererModule::Components::ClickableData createClickable(
    bool isHovered, bool isClicked, sf::Texture _texture, sf::Sprite _sprite,
    std::string _name, std::string _path, std::string _ptr,
    std::pair<float, float> _pos, std::pair<float, float> _scale,
    std::uint32_t _id) {
    Engine::RendererModule::Components::ClickableData Clickable = {
        isHovered, isClicked, _texture, _sprite, _name,
        _path,     _ptr,      _pos,     _scale,  _id};
    return Clickable;
}

int main() {
    Game game;

    uint32_t buttonPlayEntity =
        game.getGameEngine().getEntityManager()->createEntity();
    uint32_t CakeEntity =
        game.getGameEngine().getEntityManager()->createEntity();
    uint32_t BackgroundEntity =
        game.getGameEngine().getEntityManager()->createEntity();
    uint32_t TitleEntity =
        game.getGameEngine().getEntityManager()->createEntity();

    sf::Font     font;
    unsigned int WIDTH = sf::VideoMode::getDesktopMode().width;
    unsigned int HEIGHT = sf::VideoMode::getDesktopMode().height;

    if (!font.loadFromFile("src/Client/src/Roboto-Bold.ttf")) {
        std::cout << "cant load this shit" << std::endl;
    }

    Engine::RendererModule::Components::TextData Title =
        createText("Welcome on the R-Type game", font, sf::Color::White,
                   {float(WIDTH / 6), float(HEIGHT / 14)}, {1, 1}, 0);

    Engine::RendererModule::Components::TextComponent titleComponent(Title);

    sf::Texture texture;
    sf::Sprite  sprite;

    Engine::RendererModule::Components::SpriteData spriteBackgroundData =
        createSprite(
            BackgroundEntity,
            "src/Client/assets/Background/Layers/layer01_ground.png", "jsp",
            texture, sprite,
            {float((WIDTH * 10) / 100) * -1, float((HEIGHT * 10) / 100) * -1});
    Engine::RendererModule::Components::SpriteComponent BackgroundComponent(
        spriteBackgroundData);

    Engine::RendererModule::Components::SpriteData spriteCakeData =
        createSprite(
            CakeEntity, "src/Client/assets/Background/Layers/layer02_cake.png",
            "jsp", texture, sprite,
            {float((WIDTH * 10) / 100) * -1, float((HEIGHT * 10) / 100) * -1});
    Engine::RendererModule::Components::SpriteComponent CakeComponent(
        spriteCakeData);

    Engine::RendererModule::Components::ClickableData buttonData =
        createClickable(false, false, texture, sprite, "Play",
                        "src/Client/assets/Buttons/start.png", "jsp",
                        {float((WIDTH * 20) / 100), float((HEIGHT * 8) / 100)},
                        {0.5, 0.5}, buttonPlayEntity);

    Engine::RendererModule::Components::ClickableComponent buttonComponent(
        buttonData);


    // std::vector<Engine::RendererModule::Components::parallaxData> parallaxData {
    //     {
    //         texture,
    //         sprite,
    //         "Background",
    //         "src/Client/assets/Background/Layers/layer01_ground.png",
    //         "jsp",
    //         {float((WIDTH * 10) / 100) * -1, float((HEIGHT * 10) / 100) * -1},
    //         {1, 1},
    //         {0.1, 0.1},
    //         game.getGameEngine().getEntityManager()->createEntity()
    //     },
    //     {
    //         texture,
    //         sprite,
    //         "Cake",
    //         "src/Client/assets/Background/Layers/layer02_cake.png",
    //         "jsp",
    //         {float((WIDTH * 10) / 100) * -1, float((HEIGHT * 10) / 100) * -1},
    //         {1, 1},
    //         {0.2, 0.2},
    //         game.getGameEngine().getEntityManager()->createEntity()
    //     }, {
    //         texture,
    //         sprite,
    //         "Cake",
    //         "src/Client/assets/Background/Layers/layer02_cake.png",
    //         "jsp",
    //         {float((WIDTH * 10) / 100) * -1, float((HEIGHT * 10) / 100) * -1},
    //         {1, 1},
    //         {0.3, 0.3},
    //         game.getGameEngine().getEntityManager()->createEntity()
    //     }
    // };

    // Engine::RendererModule::Components::parallaxComponent parallaxComponent();

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(TitleEntity),
        titleComponent);

    game.getGameEngine().getEntityManager()->addComponent(
        game.getGameEngine().getEntityManager()->getEntity(buttonPlayEntity),
        buttonComponent);

    // game.getGameEngine().getEntityManager()->addComponent(
    //     game.getGameEngine().getEntityManager()->getEntity(BackgroundEntity),
    //     BackgroundComponent);

    // game.getGameEngine().getEntityManager()->addComponent(
    //     game.getGameEngine().getEntityManager()->getEntity(CakeEntity),
    //     CakeComponent);

    game.addEntity(buttonPlayEntity);
    game.addEntity(BackgroundEntity);
    game.addEntity(CakeEntity);
    game.addEntity(TitleEntity);

    game.run();
    return 0;
}
