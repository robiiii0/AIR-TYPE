/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** main
*/

#include "../../GameEngine/GameEngine.hpp"
#include "./Game/Game.hpp"

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

    //    uint32_t buttonPlayEntity =
    //        game.getGameEngine().getEntityManager()->createEntity();

    //    uint32_t BackgroundEntity =
    //        game.getGameEngine().getEntityManager()->createEntity();
    //

    //
    //    Engine::RendererModule::Components::SpriteData spriteBackgroundData =
    //        createSprite(
    //            BackgroundEntity,
    //            "src/Client/assets/Background/Layers/layer01_ground.png",
    //            "jsp", texture, sprite, {float((WIDTH * 10) / 100) * -1,
    //            float((HEIGHT * 10) / 100) * -1});
    //    Engine::RendererModule::Components::SpriteComponent
    //    BackgroundComponent(
    //        spriteBackgroundData);
    //

    //
    //    Engine::RendererModule::Components::ClickableData buttonData =
    //        createClickable(false, false, texture, sprite, "Play",
    //                        "src/Client/assets/Buttons/start.png", "jsp",
    //                        {float((WIDTH * 20) / 100), float((HEIGHT * 8) /
    //                        100)}, {0.5, 0.5}, buttonPlayEntity);
    //
    //    Engine::RendererModule::Components::ClickableComponent
    //    buttonComponent(
    //        buttonData);

    //    // game.getGameEngine().getEntityManager()->addComponent(
    //    //
    //    game.getGameEngine().getEntityManager()->getEntity(buttonPlayEntity),
    //    //     buttonComponent);
    //
    //    // game.getGameEngine().getEntityManager()->addComponent(
    //    //
    //    game.getGameEngine().getEntityManager()->getEntity(BackgroundEntity),
    //    //     BackgroundComponent);
    //

    //
    //    // game.addEntity(buttonPlayEntity);
    //    // game.addEntity(BackgroundEntity);

    game.setLobby();
    game.run();
    return 0;
}
