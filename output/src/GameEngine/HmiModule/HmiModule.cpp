//
// Created by Valentin Woehrel on 01/01/2024.
//

#include "HmiModule.hpp"

Engine::HmiModule::HmiModule() {
    keyboard.reset();
    std::cout << "HmiModule created" << std::endl;
}

void Engine::HmiModule::keyEvent(int key) {
    switch (key) {
        case sf::Keyboard::Up:
            keyboard.set(0);
            std::cout << "Up" << std::endl;
            break;
        case sf::Keyboard::Down:
            keyboard.set(1);
            std::cout << "Down" << std::endl;
            break;
        case sf::Keyboard::Left:
            keyboard.set(2);
            std::cout << "Left" << std::endl;
            break;
        case sf::Keyboard::Right:
            keyboard.set(3);
            std::cout << "Right" << std::endl;
            break;
        default:
            // std::cout << "Key not handled" << std::endl;
            break;
    }
}
