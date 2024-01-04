#include "../Client.hpp"

void Client::createParallax(std::vector<sf::Texture> &Textures) {
    for (int i = 0; i < Textures.size(); i++) {
        uint32_t spriteParallaxEntity =
            _gameEngine.getEntityManager()->createEntity();

        Engine::RendererModule::Components::parallaxData parallaxData = {
            {950 + 1980 * i, 1080}, {1.3, 0.5}, {1, 1}, true,
            {0, 0, 1000, 1000},     sf::Clock()};

        std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
            parallaxComponent = std::make_shared<
                Engine::RendererModule::Components::parallaxComponent>(
                parallaxData, Textures[i]);
        _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                     parallaxComponent);
        addEntity(spriteParallaxEntity);
        std::cout << "parallaxEntity added" << std::endl;
    }
}

void Client::createBackground(sf::Texture &texture) {
    uint32_t spriteBackgroundEntity =
        _gameEngine.getEntityManager()->createEntity();

    Engine::Entity::Component::GenericComponents::Vector2f pos = {0.0, 0.0};

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            pos);
    Engine::RendererModule::Components::SpriteData sprite_temp = {
        pos, {1, 1}, sf::Color::White, 0, false};

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 texture);
    _gameEngine.getEntityManager()->addComponent(spriteBackgroundEntity,
                                                 spriteComponent);
    addEntity(spriteBackgroundEntity);
    std::cout << "backgroundEntity added" << std::endl;
}

void Client::createPlayer(std::vector<sf::Texture> &Textures) {
    std::cout << " Texture size " << Textures.size() << "Client id "
              << _ClientId << std::endl;
    for (int i = _ClientId; i < Textures.size(); i++) {
        uint32_t spritePlayerEntity =
            _gameEngine.getEntityManager()->createEntity();

        Engine::Entity::Component::GenericComponents::Vector2f pos = {250.0,
                                                                      250.0};

        std::shared_ptr<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>
            posComponent =
                std::make_shared<Engine::Entity::Component::GenericComponents::
                                     Vector2fComponent>(pos);

        Engine::RendererModule::Components::SpriteData sprite_temp = {
            pos, {2, 2}, sf::Color::White, 0, false};

        std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
            spriteComponent = std::make_shared<
                Engine::RendererModule::Components::SpriteComponent>(
                sprite_temp, Textures[i]);
        _gameEngine.getEntityManager()->addComponent(spritePlayerEntity,
                                                     spriteComponent);
        _gameEngine.getEntityManager()->addComponent(spritePlayerEntity,
                                                     posComponent);
        addEntity(spritePlayerEntity);
    }
}

void Client::LoadTexturePlayer(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturePlayer.push_back(texture);
}

void Client::LoadBackground() {
    sf::Texture texture;
    if (texture.loadFromFile(
            "src/Client/assets/new_assets/background/Menu/background.png") ==
        false) {
        std::cerr
            << "Error: could not load texture "
            << "src/Client/assets/new_assets/background/Menu/background.png"
            << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _backgroundTexture = texture;
}


void Client::LoadSettingsKeyBindings(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _textureSetting.push_back(texture);
}

void Client::LoadTextureParallax(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesParallax.push_back(texture);
}
