//
// Created by Valentin Woehrel on 01/01/2024.
//

#include "HmiModule.hpp"

Engine::HmiModule::HmiModule() {
    keyboard.reset();
    std::cout << "HmiModule created" << std::endl;
}

std::string Engine::HmiModule::keyEvent(int key) {
    switch (key) {
        case sf::Keyboard::Up:
            keyboard.set(0);
            return "up";
            break;
        case sf::Keyboard::Down:
            keyboard.set(1);
            return "down";

            break;
        case sf::Keyboard::Left:
            keyboard.set(2);
            return "left";

            break;
        case sf::Keyboard::Right:
            keyboard.set(3);
            return "right";
            break;
        case 10000:
            return "exit";
            break;
        default:
            return "nothing";
            break;
    }
}
