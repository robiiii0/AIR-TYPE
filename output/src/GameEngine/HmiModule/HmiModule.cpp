//
// Created by Valentin Woehrel on 01/01/2024.
//

#include "HmiModule.hpp"

Engine::HmiModule::HmiModule() {
    _data.keyboard.reset();
    std::cout << "HmiModule created" << std::endl;
}

Engine::HmiData &Engine::HmiModule::getData() { return _data; }

void Engine::HmiModule::keyEvent(sf::Window &window) {
    sf::Event event;

    while (window.pollEvent(event)) {
        std::cout << "Event type: ";
        std::cout << event.type << std::endl;

        // Check if the event is a key press
        if (event.type == sf::Event::KeyPressed) {
            std::cout << "Key pressed" << std::endl;

            // Process the key code
            switch (event.key.code) {
                case sf::Keyboard::Up:
                    _data.keyboard.set(0);
                    std::cout << "Up" << std::endl;
                    break;
                case sf::Keyboard::Down:
                    _data.keyboard.set(1);
                    std::cout << "Down" << std::endl;
                    break;
                case sf::Keyboard::Left:
                    _data.keyboard.set(2);
                    std::cout << "Left" << std::endl;
                    break;
                case sf::Keyboard::Right:
                    _data.keyboard.set(3);
                    std::cout << "Right" << std::endl;
                    break;
                // case sf::Keyboard::Space:
                //     _data.keyboard.set(4);
                //     std::cout << "Space" << std::endl;
                //     break;
                // case sf::Keyboard::Escape:
                //     _data.keyboard.set(5);
                //     std::cout << "Escape" << std::endl;
                //     break;
                default:
                    std::cout << "Key not handled" << std::endl;
                    break;
            }
        }
    }
}
