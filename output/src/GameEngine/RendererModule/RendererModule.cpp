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
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Escape)
            _window.close();
    }
}

sf::RenderWindow &Engine::RendererModule::RendererModule::getWindow() {
    return _window;
}

void Engine::RendererModule::RendererModule::render(
    Engine::Entity::EntityManager &entityManager, uint32_t idmax) {
    _window.clear();

    // Vérifier les événements
    while (_window.pollEvent(_event)) {
        std::cout << "test" << std::endl;
        if (_event.type == sf::Event::MouseButtonReleased) {
            std::cout << "clicked" << std::endl;
            if (_event.mouseButton.button == sf::Mouse::Right) {
                sf::Vector2i mousepos = sf::Mouse::getPosition();
            }
        }
    }

    // Dessiner les composants
    for (auto i = 0; i < idmax; i++) {
        auto components =
            entityManager.getAllComponents(entityManager.getEntity(i));
        for (auto &component : components) {
            if (typeid(*component) ==
                typeid(Engine::RendererModule::Components::TextComponent)) {
                _window.draw(
                    dynamic_cast<
                        Engine::RendererModule::Components::TextComponent *>(
                        component)
                        ->getDrawable());
            } else if (typeid(*component) ==
                       typeid(Engine::RendererModule::Components::
                                  SpriteComponent)) {
                _window.draw(
                    dynamic_cast<
                        Engine::RendererModule::Components::SpriteComponent *>(
                        component)
                        ->getDrawable());
            } else if (typeid(*component) ==
                       typeid(Engine::RendererModule::Components::
                                  ClickableComponent)) {
                _window.draw(dynamic_cast<Engine::RendererModule::Components::
                                              ClickableComponent *>(component)
                                 ->getDrawable());
            }
        }
    }

    _window.display();
}
