#include "../Client.hpp"

void Client::createParallax(std::vector<sf::Texture> &Textures) {
    {
        uint32_t spriteParallaxEntity =
            _gameEngine.getEntityManager()->createEntity();

        Engine::RendererModule::Components::parallaxData parallaxData = {
            {960, 540}, {1, 1}, {1, 1}, false, {0, 0, 0, 0}, sf::Clock()};

        std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
            parallaxComponent = std::make_shared<
                Engine::RendererModule::Components::parallaxComponent>(
                parallaxData, Textures[0]);
        _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                     parallaxComponent);
        addEntity(spriteParallaxEntity);
        std::cout << "parallaxEntity added" << std::endl;
    }

    uint32_t spriteParallaxEntity =
        _gameEngine.getEntityManager()->createEntity();

    Engine::RendererModule::Components::parallaxData parallaxData = {
        {950, 1080}, {1.3, 0.5}, {1, 1}, true, {0, 0, 1000, 1000}, sf::Clock()};

    std::shared_ptr<Engine::RendererModule::Components::parallaxComponent>
        parallaxComponent = std::make_shared<
            Engine::RendererModule::Components::parallaxComponent>(parallaxData,
                                                                   Textures[1]);
    _gameEngine.getEntityManager()->addComponent(spriteParallaxEntity,
                                                 parallaxComponent);
    addEntity(spriteParallaxEntity);
    std::cout << "parallaxEntity added" << std::endl;
}

// std::vector<sf::Texture> Client::LoadTextures(std::vector<std::string> paths)
// {

//     std::vector<sf::Texture> textures;

//     for (auto path : paths) {
//         sf::Texture texture;
//         if (texture.loadFromFile(path) == false) {
//             std::cerr << "Error: could not load texture " << path <<
//             std::endl; exit(84);
//         }
//         texture.setSmooth(true);
//         _texturesParallax.push_back(texture);
//     }
// }
