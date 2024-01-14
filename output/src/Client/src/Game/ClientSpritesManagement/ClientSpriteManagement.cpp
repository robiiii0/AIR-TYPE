#include "../Client.hpp"

void Client::LoadTextureParallax(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesParallax.push_back(texture);
}


void Client::DuplicateParalax(sf::Texture &Texture, int i)
{

        uint32_t spriteParallaxEntity =
        _gameEngine.getEntityManager()->createEntity();

        Engine::RendererModule::Components::parallaxData parallaxData = {
            {i * 1940, 500}, {float(1920 / Texture.getSize().x + 0.5), float(1080 / Texture.getSize().y + 0.5)}, {-10, 0}, false,
            {0, 0, 0, 0},     sf::Clock()};

        std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
            parallaxComponent = std::make_shared<
                Engine::RendererModule::Components::parallaxComponent>(
                parallaxData, Texture);
        _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                     parallaxComponent);
        addEntity(spriteParallaxEntity);
}

void Client::createParallax(std::vector<sf::Texture> &Textures) {
    for (int i = 0; i < Textures.size(); i++) {
        for (int j = 0 ; j < 3; j++) {
            DuplicateParalax(Textures[i], j);
        }
    }
}

void Client::LoadBackground() {
    sf::Texture texture;
    if (texture.loadFromFile("src/Client/assets/new_assets/background/Menu/"
                             "background.png") == false) {
        std::cerr
            << "Error: could not load texture "
            << "src/Client/assets/new_assets/background/Menu/background.png"
            << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _backgroundTexture = texture;
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
}

void Client::LoadTextureEnemies(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesEnemies.push_back(texture);
}

void Client::createEnemy(sf::Texture &Textures) {
    uint32_t EnemyEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::Entity::Component::GenericComponents::Vector2f pos = {500.0, 500.0};

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            pos);

    Engine::RendererModule::Components::EnemyData sprite_temp = {
        pos, {2, 2}, sf::Color::White, 0, false};

    std::shared_ptr<Engine::RendererModule::Components::EnemyComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::EnemyComponent>(sprite_temp,
                                                                Textures);
    _gameEngine.getEntityManager()->addComponent(EnemyEntity, spriteComponent);
    _gameEngine.getEntityManager()->addComponent(EnemyEntity, posComponent);
    addEntity(EnemyEntity);
}

void Client::LoadTextureBoss(std::string path) {
    sf::Texture texture;
    if (texture.loadFromFile(path) == false) {
        std::cerr << "Error: could not load texture " << path << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _textureBoss = texture;
}

void Client::CreateBoss(
    Engine::Entity::Component::GenericComponents::Vector2f pos,
    Engine::Entity::Component::GenericComponents::Vector2f scale,
    sf::Texture &texture, sf::IntRect &rect) {
    uint32_t BossEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::Entity::Component::GenericComponents::Vector2f position = {250.0,
                                                                       250.0};

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            pos);
    Engine::RendererModule::Components::BossData sprite_temp = {
        position, scale, sf::Color::White, 0, rect};

    std::shared_ptr<Engine::RendererModule::Components::BossComponent>
        spriteComponent =
            std::make_shared<Engine::RendererModule::Components::BossComponent>(
                sprite_temp, texture);
    _gameEngine.getEntityManager()->addComponent(BossEntity, spriteComponent);
    _gameEngine.getEntityManager()->addComponent(BossEntity, posComponent);
    addEntity(BossEntity);
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

uint32_t Client::createPlayer(
    sf::Texture                                           &Textures,
    Engine::Entity::Component::GenericComponents::Vector2f pos) {
    uint32_t PlayerEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::Entity::Component::GenericComponents::Vector2f position = {pos.x,
                                                                       pos.y};

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            position);
    Engine::RendererModule::Components::SpriteData sprite_temp = {
        position, {1, 1}, sf::Color::White, 0, false, PlayerEntity};

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 Textures);
    _gameEngine.getEntityManager()->addComponent(PlayerEntity, spriteComponent);
    _gameEngine.getEntityManager()->addComponent(PlayerEntity, posComponent);
    addEntity(PlayerEntity);
    return PlayerEntity;
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

uint32_t Client::createMissile(std::uint32_t id, float x, float y) {
    uint32_t missileEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::Entity::Component::GenericComponents::Vector2f pos = {x, y};

    std::shared_ptr<
        Engine::Entity::Component::GenericComponents::Vector2fComponent>
        posComponent = std::make_shared<
            Engine::Entity::Component::GenericComponents::Vector2fComponent>(
            pos);

    Engine::RendererModule::Components::SpriteData sprite_temp = {
        pos, {1, 1}, sf::Color::White, 0, false, missileEntity};

    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(
            sprite_temp, _textureMissile);
    _gameEngine.getEntityManager()->addComponent(missileEntity,
                                                 spriteComponent);
    _gameEngine.getEntityManager()->addComponent(missileEntity, posComponent);
    addEntity(missileEntity);
    return missileEntity;
}
