#include "../Client.hpp"

void Client::CreateSprite(
    Engine::Entity::Component::GenericComponents::Vector2f pos,
    Engine::Entity::Component::GenericComponents::Vector2f scale,
    sf::Texture &texture, std::string name) {
    uint32_t spriteEntity = _gameEngine.getEntityManager()->createEntity();

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            pos);

    Engine::RendererModule::Components::TextData tmp_text = {
        name, _fonts[0], sf::Color::White, {pos.x, pos.y}, {1, 1}, 0};

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        textComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                tmp_text);

    Engine::RendererModule::Components::ClickableData tmp_clickable = {
        {pos.x, pos.y}, {scale.x, scale.y}, sf::Color::White, 0};

    std::shared_ptr<Engine::RendererModule::Components::ClickableComponent>
        clickableComponent = std::make_shared<
            Engine::RendererModule::Components::ClickableComponent>(
            tmp_clickable, texture, [this]() {});

    _gameEngine.getEntityManager()->addComponent(spriteEntity,
                                                 clickableComponent);
    _gameEngine.getEntityManager()->addComponent(spriteEntity, textComponent);
    addEntity(spriteEntity);
}




