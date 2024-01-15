//
// Created by Valentin Woehrel on 01/01/2024.
//

#include "HmiModule.hpp"

Engine::HmiModule::HmiModule() {}

std::string Engine::HmiModule::keyEvent(int key) {
    switch (key) {
        case sf::Keyboard::Up:
            return "up";
            break;
        case sf::Keyboard::Down:
            return "down";

            break;
        case sf::Keyboard::Left:
            return "left";
            break;
        case sf::Keyboard::Right:
            return "right";
            break;
        case sf::Keyboard::K:
            return "attack";
            break;
        case 10000:
            return "exit";
            break;
        default:
            return "nothing";
            break;
    }
}
