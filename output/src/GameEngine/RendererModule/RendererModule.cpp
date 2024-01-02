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

int Engine::RendererModule::RendererModule::UpdateForServer(
    Engine::Entity::EntityManager &entityManager,
    std::vector<uint32_t>          id_list) {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) _window.close();
        if (_event.type == sf::Event::KeyPressed &&
            _event.key.code == sf::Keyboard::Escape)
            _window.close();
        if (_event.type == sf::Event::MouseButtonPressed) {
            std::cout << "cliqued" << std::endl;
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

        // if (_event.type == sf::Event::KeyPressed) {
        //     for (auto id : id_list) {
        //         try {
        //             auto components = entityManager.getAllComponents(id);
        //             for (auto &component : components) {
        //                 if (typeid(*component) ==
        //                     typeid(Engine::RendererModule::Components::
        //                                SpriteComponent)) {
        //                     std::dynamic_pointer_cast<
        //                         Engine::RendererModule::Components::
        //                             SpriteComponent>(component)
        //                         ->handleEvent(_event.key.code);
        //                 }
        //             }
        //         } catch (const Engine::EntityManager::NoComponent &e) {
        //             std::cerr << e.what() << '\n';
        //         }
        //     }
        // }
        // //        if (_event.type == sf::Event::KeyPressed) {
        // //        }
        // if (_event.type == sf::Event::TextEntered ||
        //     _event.type == sf::Event::KeyPressed) {
        //     for (auto id : id_list) {
        //         try {
        //             auto components = entityManager.getAllComponents(id);
        //             for (auto &component : components) {
        //                 if (typeid(*component) ==
        //                     typeid(Engine::RendererModule::Components::
        //                                InputComponent)) {
        //                     bool isClicked =
        //                         std::dynamic_pointer_cast<
        //                             Engine::RendererModule::Components::
        //                                 InputComponent>(component)
        //                             ->getClicked();
        //                     if (isClicked) {
        //                         std::dynamic_pointer_cast<
        //                             Engine::RendererModule::Components::
        //                                 InputComponent>(component)
        //                             ->handleEvent(_event);

        //                     }
        //                 }
        //             }
        //         } catch (const Engine::EntityManager::NoComponent &e) {
        //             std::cerr << e.what() << '\n';
        //         }
        //     }
        // }
        // if (_event.type == sf::Event::MouseButtonPressed) {
        //     for (auto id : id_list) {
        //         try {
        //             auto components = entityManager.getAllComponents(id);
        //             for (auto &component : components) {
        //                 if (typeid(*component) ==
        //                     typeid(Engine::RendererModule::Components::
        //                                InputComponent)) {
        //                     bool isClicked =
        //                         std::dynamic_pointer_cast<
        //                             Engine::RendererModule::Components::
        //                                 InputComponent>(component)
        //                             ->isClicked(
        //                                 std::make_pair(_event.mouseButton.x,
        //                                                _event.mouseButton.y));

        //                 }
        //                 if (typeid(*component) ==
        //                     typeid(Engine::RendererModule::Components::
        //                                ClickableComponent)) {
        //                     bool isClicked =
        //                         std::dynamic_pointer_cast<
        //                             Engine::RendererModule::Components::
        //                                 ClickableComponent>(component)
        //                             ->isClicked(
        //                                 std::make_pair(_event.mouseButton.x,
        //                                                _event.mouseButton.y));

        //                 }
        //                 if (typeid(*component) ==
        //                     typeid(Engine::RendererModule::Components::
        //                                RoundedClickableComponent)) {
        //                     bool isClicked =
        //                         std::dynamic_pointer_cast<
        //                             Engine::RendererModule::Components::
        //                                 RoundedClickableComponent>(component)
        //                             ->isClicked(
        //                                 std::make_pair(_event.mouseButton.x,
        //                                                _event.mouseButton.y));

        //                 }
        //             }
        //         } catch (const Engine::EntityManager::NoComponent &e) {
        //             std::cerr << e.what() << '\n';
        //         }
        //     }
            if (_event.type == sf::Event::KeyPressed) {
            std::cout << "jappuie" << std::endl;
            return _event.key.code;
            }

        // }
    }
    return 0;
}

// TODO : refaire tout le fichier là ça va pas le code omg bande de cochons

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
                    // If it is, update the component
                    parallaxComp->runParallax();
                }
                if (auto clickableComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::ClickableComponent>(
                        component)) {
                    // If it is, update the component
                    clickableComp->isHovered(
                        {sf::Mouse::getPosition(_window).x,
                         sf::Mouse::getPosition(_window).y});
                }
                if (auto clickableComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::
                            RoundedClickableComponent>(component)) {
                    // If it is, update the component
                    clickableComp->isHovered(
                        {sf::Mouse::getPosition(_window).x,
                         sf::Mouse::getPosition(_window).y});
                }
                if (auto spriteComp = std::dynamic_pointer_cast<
                        Engine::RendererModule::Components::SpriteComponent>(
                        component)) {
                    for (auto &component2 : components) {
                        if (auto posComp = std::dynamic_pointer_cast<
                                Engine::Entity::Component::GenericComponents::
                                    PositionComponent>(component2)) {
                            spriteComp->setPosition(posComp->getValue().x,
                                                    posComp->getValue().y);
                        }
                    }
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
