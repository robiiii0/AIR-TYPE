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
    CreateSprite({450, 250}, {0.3, 0.3}, _textureSetting[UP_TEXTURE], "Key Up");
    CreateSprite({250, 450}, {0.3, 0.3}, _textureSetting[LEFT_TEXTURE], "Key Left");
    CreateSprite({450, 450}, {0.3, 0.3}, _textureSetting[DOWN_TEXTURE], "Key Down");
    CreateSprite({650, 450}, {0.3, 0.3}, _textureSetting[RIGHT_TEXTURE], "Key Right");
    CreateSprite({850, 250}, {0.3, 0.3}, _textureSetting[ATTACK_TEXTURE], "Attack");
}


void Client::setSetting()
{
    // call this function to change key
    // ChangeKeyBinding();
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


    createText("Volume", _fonts[0],
               {static_cast<float>(_screenWidth / 2 + 100),static_cast<float>(_screenHeight / 3 - 50)},
               {1, 1}, sf::Color::White, 0);
    // value of volume.
    createText("100", _fonts[0],
               {static_cast<float>(_screenWidth / 2 + 100), static_cast<float>(_screenHeight / 3)},
               {0.5, 0.5}, sf::Color::White, 0);
    // Button volume -.
    createButton([this]() {},"-",_texturesButton[1],  _fonts[0],
                        {static_cast<float>(_screenWidth / 2 - 50), static_cast<float>(_screenHeight /3)},
                        {0.2, 0.2}, sf::Color::White
                        ,0);
    // Button volume +.
    createButton([this]() {},"+",_texturesButton[1],  _fonts[0],
                        {static_cast<float>(_screenWidth / 2 + 250), static_cast<float>(_screenHeight / 3)},
                        {0.2, 0.2}, sf::Color::White
                        , 0);
}