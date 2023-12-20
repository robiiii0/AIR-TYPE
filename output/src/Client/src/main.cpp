/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** main
*/

#include "../../GameEngine/GameEngine.hpp"
#include "./Game/Game.hpp"

Engine::RendererModule::Components::SpriteData createSprite(
    std::uint32_t _id, std::string _path, std::string _ptr,
    sf::Texture &_texture, sf::Sprite &_sprite, std::pair<float, float> pos) {
    Engine::RendererModule::Components::SpriteData Sprite = {
        _id, _texture, _sprite, _path, _ptr, pos};
    return Sprite;
}

int main() {
    Game game;

    //    uint32_t buttonPlayEntity =
    //        game.getGameEngine().getEntityManager()->createEntity();
    //    uint32_t CakeEntity =
    //        game.getGameEngine().getEntityManager()->createEntity();
    //    uint32_t BackgroundEntity =
    //        game.getGameEngine().getEntityManager()->createEntity();
    //
    //    sf::Texture texture;
    //    sf::Sprite  sprite;
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
    //    Engine::RendererModule::Components::SpriteData spriteCakeData =
    //        createSprite(
    //            CakeEntity,
    //            "src/Client/assets/Background/Layers/layer02_cake.png", "jsp",
    //            texture, sprite, {float((WIDTH * 10) / 100) * -1,
    //            float((HEIGHT * 10) / 100) * -1});
    //    //
    //    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
    //    // CakeComponent;
    //    auto CakeComponent =
    //        std::make_shared<Engine::RendererModule::Components::SpriteComponent>(
    //            spriteCakeData);
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
    //
    //
    //
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
    //    game.getGameEngine().getEntityManager()->addComponent(CakeEntity,
    //                                                          CakeComponent);
    //
    //    // game.addEntity(buttonPlayEntity);
    //    // game.addEntity(BackgroundEntity);
    //    game.addEntity(CakeEntity);
    game.setHomepage();
    game.run();
    return 0;
}
