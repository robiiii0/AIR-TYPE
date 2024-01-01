//
// Created by Valentin Woehrel on 01/01/2024.
//

#ifndef NETWORKING_HMIMODULE_HPP
#define NETWORKING_HMIMODULE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <bitset>

namespace Engine {
    struct HmiData {
        std::bitset<8> keyboard;
    };

        class HmiModule {
            public:
                HmiModule();
                ~HmiModule() = default;

                HmiData &getData();

                void keyEvent(sf::Event &event);

            private:
            /**
                 * @brief up = 0, down = 1, left = 2, right = 3, space = 4,
                 * escape = 5
                 *
            */
            HmiData _data{};
        };
}  // namespace Engine

#endif //NETWORKING_HMIMODULE_HPP
