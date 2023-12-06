/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** HmiModule
*/

#ifndef HMIMODULE_HPP_
#define HMIMODULE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <bitset>

typedef struct mouse_pos_s {
        unsigned int x;
        unsigned int y;
} mouse_pos_t;

namespace Engine {
    namespace Hmi {
        class HmiModule {
            public:
                HmiModule(sf::RenderWindow* window);
                ~HmiModule();

                void update();

                mouse_pos_t getMousePos() const;
                bool        isMousePressed() const;
                bool        isKeyPressed(const std::string) const;

            private:
                sf::RenderWindow _window;
                bool             _mouse_pressed;

                /**
                 * @brief (x, y)
                 *
                 */
                mouse_pos_t _mouse_pos;

                /**
                 * @brief up = 0, down = 1, left = 2, right = 3, space = 4,
                 * escape = 5
                 *
                 */
                std::bitset<6> _keyboard;
        };
    };  // namespace Hmi
};      // namespace Engine

#endif /* !HMIMODULE_HPP_ */
