/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** RendererModule
*/

#include "RendererModule.hpp"

Engine::RendererModule::RendererModule::RendererModule() {}

Engine::RendererModule::RendererModule::~RendererModule() {}

void Engine::RendererModule::RendererModule::init(int width, int height,
                                                  std::string title,
                                                  int         framerate) {
    _window.create(sf::VideoMode(width, height), title);
    _window.setFramerateLimit(framerate);
}

void Engine::RendererModule::RendererModule::
    update() {  // update les animations, la camera, etc
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) _window.close();
    }
}

sf::RenderWindow &Engine::RendererModule::RendererModule::getWindow() {
    return _window;
}

void Engine::RendererModule::RendererModule::render(
    Engine::Entity::EntityManager &entityManager, uint32_t idmax) {
    _window.clear();
    for (auto i = 0; i < idmax; i++) {
        auto text = entityManager.getAllComponents(entityManager.getEntity(i));
        for (auto &component : text) {
            if (typeid(*component) ==
                typeid(Engine::RendererModule::Components::TextComponent)) {
                _window.draw(
                    dynamic_cast<
                        Engine::RendererModule::Components::TextComponent *>(
                        component)
                        ->getDrawable());
            }
            if (typeid(*component) ==
                typeid(Engine::RendererModule::Components::SpriteComponent)) {
                _window.draw(
                    dynamic_cast<
                        Engine::RendererModule::Components::SpriteComponent *>(
                        component)
                        ->getDrawable());
            }
            if (typeid(*component) ==
                typeid(Engine::RendererModule::Components::ClickableComponent)) {
                    
                _window.draw(
                    dynamic_cast<
                        Engine::RendererModule::Components::ClickableComponent *>(
                        component)
                        ->getDrawable());

            }
        }
    }

    _window.display();
}
