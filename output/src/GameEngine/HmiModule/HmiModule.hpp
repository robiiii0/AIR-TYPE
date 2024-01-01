//
// Created by Valentin Woehrel on 01/01/2024.
//

#ifndef NETWORKING_HMIMODULE_HPP
#define NETWORKING_HMIMODULE_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

namespace Engine {
    struct HmiData {
        int id;
    };

        class HmiModule {
            public:
                HmiModule();
                ~HmiModule() = default;

            private:
            HmiData _data{};
        };
}  // namespace Engine

#endif //NETWORKING_HMIMODULE_HPP
