#include "../Client.hpp"

void Client::LoadTextureButton(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesButton.push_back(texture);
}

void Client::LoadFont(std::string paths) {
    sf::Font font;
    if (font.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load font " << paths << std::endl;
        exit(84);
    }
    _fonts.push_back(font);
}

void Client::createButton(std::function<void()> func, std::string text,
                          sf::Texture &texture, sf::Font &font,
                          sf::Vector2f position, sf::Vector2f scale,
                          sf::Color color, float rotation) {
    uint32_t   button_entity = _gameEngine.getEntityManager()->createEntity();

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

void Client::createText(std::string text, sf::Font &font, Engine::Entity::Component::GenericComponents::Vector2f position,
                        Engine::Entity::Component::GenericComponents::Vector2f scale, sf::Color color, float rotation) {
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

void Client::LoadTextureMissile(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _textureMissile = texture;
}
