#include "../Client.hpp"

void Client::createBackground(sf::Texture &texture)
{
    uint32_t spriteBackgroundEntity =
        _gameEngine.getEntityManager()->createEntity();


    Engine::RendererModule::Components::SpriteData sprite_temp = {
        {960, 540}, {1, 1}, sf::Color::White, 0, false};

        std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 texture);


    _gameEngine.getEntityManager()->addComponent(spriteBackgroundEntity,
                                                spriteComponent);
    addEntity(spriteBackgroundEntity);
    std::cout << "backgroundEntity added" << std::endl;
}


void Client::createPlayer() {
    sf::Texture texture;
    if (texture.loadFromFile("src/Client/assets/new_assets/Player/sprtes/player1_yellow.png") == false) {
        std::cerr << "Error: could not load texture " << "src/Client/assets/new_assets/Player/Player.png" << std::endl;
        exit(84);
    }

    uint32_t playerEntity = _gameEngine.getEntityManager()->createEntity();

    Engine::Entity::Component::GenericComponents::Vector2f position_data = {0, 0};
    auto position = std::make_shared<Engine::Entity::Component::GenericComponents::Vector2fComponent>(position_data);

    Engine::RendererModule::Components::SpriteData sprite_temp_data = {{0, 0}, {1, 1}, sf::Color::White, 0, false};
    std::shared_ptr<Engine::RendererModule::Components::SpriteComponent> spriteComponent = std::make_shared<Engine::RendererModule::Components::SpriteComponent>(sprite_temp_data, texture);

    _gameEngine.getEntityManager()->addComponent(playerEntity, position);
    addEntity(playerEntity);
    std::cout << "playerEntity added" << std::endl;
}


void Client::LoadBackground()
{
    sf::Texture texture;
    if (texture.loadFromFile("src/Client/assets/new_assets/background/Menu/background.png") == false) {
        std::cerr << "Error: could not load texture " << "src/Client/assets/new_assets/background/Menu/background.png" << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _backgroundTexture = texture;
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

void Client::createParallax(std::vector<sf::Texture> &Textures)
{
    for (int i = 0; i < Textures.size(); i++) {
        uint32_t spriteParallaxEntity =
            _gameEngine.getEntityManager()->createEntity();

        Engine::RendererModule::Components::parallaxData parallaxData = {
            {950 + 1980 * i,1080}, {1.3 ,0.5},
            {1,1},  true, {0,0,1000,1000}, sf::Clock()};

        std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
            parallaxComponent = std::make_shared<Engine::RendererModule::Components::parallaxComponent>(parallaxData,
                                                                                                            Textures[i]);
        _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                    parallaxComponent);
        addEntity(spriteParallaxEntity);
        std::cout << "parallaxEntity added" << std::endl;
    }
}

