/*
** EPITECH PROJECT, 2024
** AIR-TYPE
** File description:
** GameEntityLoadingManagement
*/

#include "../Game.hpp"

void Game::LoadFont(std::string paths) {
    sf::Font font;
    if (font.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load font " << paths << std::endl;
        exit(84);
    }
    _fonts.push_back(font);
}

void Game::LoadTexture(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _textures.push_back(texture);
}

void Game::LoadTextureButton(std::string paths) {
    sf::Texture texture;
    if (texture.loadFromFile(paths) == false) {
        std::cerr << "Error: could not load texture " << paths << std::endl;
        exit(84);
    }
    texture.setSmooth(true);
    _texturesButton.push_back(texture);
}

void Game::LoadSound(std::string paths, bool loop, bool play, float volume) {
    Engine::RendererModule::Components::SoundData data = {paths, loop, play,
                                                          volume};

    std::shared_ptr<Engine::RendererModule::Components::SoundComponent>
        soundComponent = std::make_shared<
            Engine::RendererModule::Components::SoundComponent>(data);

    _sounds.push_back(soundComponent);
}
