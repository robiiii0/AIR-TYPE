#include "../Client.hpp"

void Client::createParallax(std::vector<sf::Texture> Textures)
{
    for (auto &i : Textures) {
        uint32_t spriteParallaxEntity =
            _gameEngine.getEntityManager()->createEntity();

        sf::Sprite sprite_temp;

        Engine::RendererModule::Components::parallaxData parallaxData = {
            sprite_temp, "paralaxData",      {0,0}, {1,1},
            {1,1},  false, {0,0,0,0}, sf::Clock()};

        std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
            parallaxComponent = std::make_shared<
                Engine::RendererModule::Components::parallaxComponent>(parallaxData,
                                                                    i);
        _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                    parallaxComponent);
        addEntity(spriteParallaxEntity);
    }
}

std::vector<sf::Texture> Client::LoadTextures(std::vector<std::string> paths) {
    std::vector<sf::Texture> textures;

    for (auto path : paths) {
        sf::Texture texture;
        if (texture.loadFromFile(path) == false) {
            std::cerr << "Error: could not load texture " << path << std::endl;
            exit(84);
        }
        textures.push_back(texture);
    }
    return textures;
}