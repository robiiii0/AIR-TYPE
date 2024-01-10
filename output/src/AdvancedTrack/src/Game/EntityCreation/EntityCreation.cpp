/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameEntityCreationManagement
*/

#include "../Game.hpp"

void Game::createSprite(
    Engine::Entity::Component::GenericComponents::Vector2f pos,
    Engine::Entity::Component::GenericComponents::Vector2f scale,
    sf::Texture &texture, std::string name) {
    uint32_t spriteEntity = _gameEngine.getEntityManager()->createEntity();

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            pos);

    Engine::RendererModule::Components::SpriteData tmp_sprite = {
        pos, scale, sf::Color::White, 0, false};

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(tmp_sprite,
                                                                 texture);

    Engine::RendererModule::Components::TextData tmp_text = {
        name, _fonts[0], sf::Color::White, {pos.x, pos.y}, {1, 1}, 0};

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        textComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                tmp_text);

    Engine::Physic::Components::MovementData tmp_movement = {{0, 0}, {0, 0}, 0};

    _gameEngine.getEntityManager()->addComponent(spriteEntity, posComponent);
    _gameEngine.getEntityManager()->addComponent(spriteEntity, spriteComponent);
    _gameEngine.getEntityManager()->addComponent(spriteEntity, textComponent);

    addEntity(spriteEntity);
}

void Game::createText(
    std::string text, sf::Font &font,
    Engine::Entity::Component::GenericComponents::Vector2f position,
    Engine::Entity::Component::GenericComponents::Vector2f scale,
    sf::Color color, float rotation) {
    uint32_t text_entity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::TextData tmp_text = {
        text, font, color, position, scale, rotation};

    std::shared_ptr<Engine::RendererModule::Components::TextComponent>
        textComponent =
            std::make_shared<Engine::RendererModule::Components::TextComponent>(
                tmp_text);

    _gameEngine.getEntityManager()->addComponent(text_entity, textComponent);
    addEntity(text_entity);
}

void Game::createButton(std::function<void()> func, std::string text,
                        sf::Texture &texture, sf::Font &font,
                        sf::Vector2f position, sf::Vector2f scale,
                        sf::Color color, float rotation) {
    uint32_t button_entity = _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::ClickableData tmp_clickable = {
        position, scale, color, rotation};

    std::shared_ptr<Engine::RendererModule::Components::ClickableComponent>
        clickableComponent = std::make_shared<
            Engine::RendererModule::Components::ClickableComponent>(
            tmp_clickable, texture, func);

    _gameEngine.getEntityManager()->addComponent(button_entity,
                                                 clickableComponent);

    addEntity(button_entity);
    if (!text.empty()) {
        createText(text, font,
                   {static_cast<float>(position.x),
                    static_cast<float>(position.y - 6)},
                   {static_cast<float>(scale.x + 0.6),
                    static_cast<float>(scale.y + 0.6)},
                   color, rotation);
    }
}

void Game::addEntity(std::uint32_t entity) { _entities.push_back(entity); }

void Game::removeEntity(std::uint32_t entity) {
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity),
                    _entities.end());
}

std::vector<std::uint32_t> &Game::getEntities() { return _entities; }
