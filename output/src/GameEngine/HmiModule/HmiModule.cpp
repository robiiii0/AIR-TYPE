//
// Created by Valentin Woehrel on 01/01/2024.
//

#include "HmiModule.hpp"

Engine::HmiModule::HmiModule() {
    _data.id = 0;
}

void Engine::HmiModule::keyEvent(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
            _data.id = 1;
        if (event.key.code == sf::Keyboard::Down)
            _data.id = 2;
        if (event.key.code == sf::Keyboard::Left)
            _data.id = 3;
        if (event.key.code == sf::Keyboard::Right)
            _data.id = 4;
        if (event.key.code == sf::Keyboard::Escape)
            _data.id = 5;
    }
}