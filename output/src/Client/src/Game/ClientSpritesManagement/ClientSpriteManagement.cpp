#include "../Client.hpp"

void Client::createBackground(sf::Texture &texture)
{
    uint32_t spriteBackgroundEntity =
        _gameEngine.getEntityManager()->createEntity();

    sf::Sprite sprite_temp_temp;

    Engine::RendererModule::Components::SpriteData sprite_temp = {
        sprite_temp_temp, {960, 540}, {1, 1}, sf::Color::White, 0, false};

        std::shared_ptr<Engine::RendererModule::Components::SpriteComponent>
        spriteComponent = std::make_shared<
            Engine::RendererModule::Components::SpriteComponent>(sprite_temp,
                                                                 texture);


    _gameEngine.getEntityManager()->addComponent(spriteBackgroundEntity,
                                                spriteComponent);
    addEntity(spriteBackgroundEntity);
    std::cout << "backgroundEntity added" << std::endl;
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

// std::vector<sf::Texture> Client::LoadTextures(std::vector<std::string> paths) {

//     std::vector<sf::Texture> textures;

//     for (auto path : paths) {
//         sf::Texture texture;
//         if (texture.loadFromFile(path) == false) {
//             std::cerr << "Error: could not load texture " << path << std::endl;
//             exit(84);
//         }
//         texture.setSmooth(true);
//         _texturesParallax.push_back(texture);
//     }
// }
