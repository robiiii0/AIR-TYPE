/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** RendererModule
*/

#include "RendererModule.hpp"

Engine::RendererModule::RendererModule::RendererModule() {}

Engine::RendererModule::RendererModule::~RendererModule() {}

sf::RenderWindow& Engine::RendererModule::RendererModule::getWindow() {
    return _window;
}

void Engine::RendererModule::RendererModule::init(int width, int height, std::string title, int framerate) {
    _window.create(sf::VideoMode(width, height), title);
    _window.setFramerateLimit(framerate);
}

void Engine::RendererModule::RendererModule::
    update() {  // update les animations, la camera, etc
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) _window.close();
    }
}

void Engine::RendererModule::RendererModule::render()  // draw la scene
{
    _window.clear();
//    for (auto& entity : _entities) {
//        if (!entity->hasComponent<
//                Engine::RendererModule::Components::SpriteComponent>())
//            _window.draw(sprite.sprite);
//    }
    _window.display();
}
