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

int Engine::RendererModule::RendererModule::HandleEvent(
    Engine::Entity::EntityManager &entityManager,
    std::vector<uint32_t>          id_list) {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            _window.close();
            return 10000;
        }
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Escape) {
            _window.close();
            return 10000;
        }
        if (_event.type == sf::Event::MouseButtonPressed) {
            for (auto id : id_list) {
                try {
                    auto components = entityManager.getAllComponents(id);
                    for (auto &component : components) {
                        if (typeid(*component) ==
                            typeid(Engine::RendererModule::Components::
                                       ClickableComponent)) {
                            bool isClicked =
                                std::dynamic_pointer_cast<
                                    Engine::RendererModule::Components::
                                        ClickableComponent>(component)
                                    ->isClicked(
                                        std::make_pair(_event.mouseButton.x,
                                                       _event.mouseButton.y));
                        }
                    }
                } catch (const Engine::EntityManager::NoComponent &e) {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        if (_event.type == sf::Event::KeyPressed) return _event.key.code;
    }
    return 0;
}

void Engine::RendererModule::RendererModule::UpdatePosition(
    Engine::Entity::EntityManager &entityManager, std::vector<uint32_t> id_list,
    Engine::Entity::Component::GenericComponents::Vector2f pos,
    uint32_t                                               id_sprite) {
    for (auto id : id_list) {
        try {
            auto components = entityManager.getAllComponents(id);
            for (auto &component : components) {
                if (auto spriteComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::SpriteComponent>(
                        component)) {
                    if (id_sprite == spriteComp->getId()) {
                        for (auto &component2 : components) {
                            if (auto posComp = std::dynamic_pointer_cast<
                                    Engine::Entity::Component::
                                        GenericComponents::PositionComponent>(
                                    component2)) {
                                spriteComp->setPosition(pos.x, pos.y);
                            }
                        }
                    }
                }
            }
        } catch (const Engine::EntityManager::NoComponent &e) {
            std::cerr << e.what() << '\n';
        }
    }
}

void Engine::RendererModule::RendererModule::update(
    Engine::Entity::EntityManager &entityManager,
    std::vector<uint32_t>          id_list) {
    for (auto id : id_list) {
        try {
            auto components = entityManager.getAllComponents(id);
            for (auto &component : components) {
                // Check if the component is of type parallaxComponent
                if (auto parallaxComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::parallaxComponent>(
                        component)) {
                    parallaxComp->runParallax();
                }
                if (auto clickableComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::ClickableComponent>(
                        component)) {
                    clickableComp->isHovered(
                        {sf::Mouse::getPosition(_window).x,
                         sf::Mouse::getPosition(_window).y});
                }

                if (auto textComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::TextComponent>(
                        component)) {
                    for (auto &component2 : components) {
                        if (auto posComp = std::dynamic_pointer_cast<
                                Engine::Entity::Component::GenericComponents::
                                    PositionComponent>(component2)) {
                            textComp->setPosition(posComp->getValue().x,
                                                  posComp->getValue().y);
                        }
                    }
                }
            }
        } catch (const Engine::EntityManager::NoComponent &e) {
            std::cerr << e.what() << '\n';
        }
    }
}

sf::RenderWindow &Engine::RendererModule::RendererModule::getWindow() {
    return _window;
}

void Engine::RendererModule::RendererModule::render(
    Engine::Entity::EntityManager &entityManager,
    std::vector<uint32_t>          id_list) {
    _window.clear();

    for (auto id : id_list) {
        try {
            auto components = entityManager.getAllComponents(id);
            for (auto &component : components) {
                std::shared_ptr<IRendererComponent> to_render =
                    std::dynamic_pointer_cast<
                        Engine::RendererModule::IRendererComponent>(component);
                if (to_render != nullptr) {
                    _window.draw(to_render->getDrawable());
                }
            }
        } catch (const Engine::EntityManager::NoComponent &e) {
            std::cerr << e.what() << '\n';
        }
    }

    _window.display();
}
