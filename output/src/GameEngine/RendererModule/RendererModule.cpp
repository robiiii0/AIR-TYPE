/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** RendererModule
*/

#include "RendererModule.hpp"

Engine::RendererModule::RendererModule::RendererModule()
{
}

Engine::RendererModule::RendererModule::~RendererModule()
{
}

void Engine::RendererModule::RendererModule::init()
{
    _window.create(sf::VideoMode(1920, 1080), "R-Type");
    _window.setFramerateLimit(60);
}

void Engine::RendererModule::RendererModule::update()
{ // update les animations, la camera, etc
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
    }

}

void Engine::RendererModule::RendererModule::render() // draw la scene
{
    _window.clear();
    for (auto& entity : _entities) {
        if (!entity->hasComponent<Engine::RendererModule::Components::SpriteComponent>())
            _window.draw(sprite.sprite);
    }
    _window.display();
}
