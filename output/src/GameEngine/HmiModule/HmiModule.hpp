//
// Created by Valentin Woehrel on 01/01/2024.
//

#ifndef NETWORKING_HMIMODULE_HPP
#define NETWORKING_HMIMODULE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <bitset>
#include <iostream>

namespace Engine {
    struct HmiData {
            std::bitset<8> keyboard;
    };

    class HmiModule {
        public:
            HmiModule();
            ~HmiModule() = default;

            HmiData &getData();

            std::string keyEvent(int keycode);

        private:
    };
}  // namespace Engine

#endif  // NETWORKING_HMIMODULE_HPP
