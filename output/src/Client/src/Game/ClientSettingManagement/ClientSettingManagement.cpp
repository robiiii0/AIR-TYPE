#include "../Client.hpp"

void Client::CreateSprite(
    Engine::Entity::Component::GenericComponents::Vector2f pos, Engine::Entity::Component::GenericComponents::Vector2f scale , sf::Texture &texture, std::string name
)
{
    uint32_t spriteEntity = _gameEngine.getEntityManager()->createEntity();

    std::shared_ptr<Engine::Entity::Component::GenericComponents::Vector2fComponent> posComponent = std::make_shared<Engine::Entity::Component::GenericComponents::Vector2fComponent>(pos);

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


    _gameEngine.getEntityManager()->addComponent(spriteEntity, clickableComponent);
    _gameEngine.getEntityManager()->addComponent(spriteEntity, textComponent);
    addEntity(spriteEntity);
}

void Client::ChangeKeyBinding()
{
    createBackground(_backgroundTexture);
    CreateSprite({450, 250}, {0.3, 0.3}, _textureSetting[0], "Key Up");
    CreateSprite({250, 450}, {0.3, 0.3}, _textureSetting[1], "Key Left");
    CreateSprite({450, 450}, {0.3, 0.3}, _textureSetting[2], "Key Down");
    CreateSprite({650, 450}, {0.3, 0.3}, _textureSetting[3], "Key Right");
}


void Client::setSetting()
{

    ChangeKeyBinding();
    // int nb = 0;
    // createBackground(_backgroundTexture);
    // createParallax(_texturesParallax);
    // createButton([this]() {}, "Change Key", _texturesButton[0], _fonts[0],
    //              sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x, _screenHeight / 2 - _texturesButton[0].getSize().y / nb),
    //              sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    // nb++;
    // createButton([this]() {}, "Setting", _texturesButton[0], _fonts[0],
    //              sf::Vector2f(_screenWidth / 2 - _texturesButton[0].getSize().x, _screenHeight / 2 - _texturesButton[0].getSize().y / nb),
    //              sf::Vector2f(0.5, 0.5), sf::Color::White, 0);
    // nb++;
}