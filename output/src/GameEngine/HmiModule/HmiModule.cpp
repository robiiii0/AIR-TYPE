//
// Created by Valentin Woehrel on 01/01/2024.
//

#include "HmiModule.hpp"

Engine::HmiModule::HmiModule() {
    _data.keyboard.reset();
    std::cout << "HmiModule created" << std::endl;
}

Engine::HmiData &Engine::HmiModule::getData() {
    return _data;
}

void Engine::HmiModule::keyEvent(sf::Event &event) {
    switch (event.key.code) {
        case sf::Keyboard::Up:
            _data.keyboard.set(0);
            break;
        case sf::Keyboard::Down:
            _data.keyboard.set(1);
            break;
        case sf::Keyboard::Left:
            _data.keyboard.set(2);
            break;
        case sf::Keyboard::Right:
            _data.keyboard.set(3);
            break;
        case sf::Keyboard::Space:
            _data.keyboard.set(4);
            break;
        case sf::Keyboard::Escape:
            _data.keyboard.set(5);
            break;
        default:
            break;
    }
}