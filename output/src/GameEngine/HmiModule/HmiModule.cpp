/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** HmiModule
*/

#include "HmiModule.hpp"

/**
 * @brief Construct a new Hmi Module:: Hmi Module object
 *
 * @param window
 */
Engine::Hmi::HmiModule::HmiModule(sf::RenderWindow* window)
    : _window(window),
      _mouse_pos({0, 0}),
      _mouse_pressed(false),
      _keyboard(_keyboard.reset())
{}

/**
 * @brief Destroy the Hmi Module:: Hmi Module object
 *
 */
Engine::Hmi::HmiModule::~HmiModule() {}

/**
 * @brief Update the HMI module.
 *
 */
void Engine::Hmi::HmiModule::update()
{
    sf::Event event;

    // Set default values.
    _keyboard.reset();
    _mouse_pressed = false;

    // Check for events.
    while (_window.pollEvent(event)) {
        // Check if the user closed the window.
        if (event.type == sf::Event::Closed)
            _window.close();
        // Set mouse position.
        if (event.type == sf::Event::MouseMoved) {
            _mouse_pos.x = event.mouseMove.x;
            _mouse_pos.y = event.mouseMove.y;
        }
        // Check if the user pressed the mouse.
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                _mouse_pressed = true;
            }
        }
        // Set keyboard state.
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                _keyboard[0] = true;
            if (event.key.code == sf::Keyboard::Down)
                _keyboard[1] = true;
            if (event.key.code == sf::Keyboard::Left)
                _keyboard[2] = true;
            if (event.key.code == sf::Keyboard::Right)
                _keyboard[3] = true;
            if (event.key.code == sf::Keyboard::Space)
                _keyboard[4] = true;
            if (event.key.code == sf::Keyboard::Escape)
                _keyboard[5] = true;
        }
    }
}

/**
 * @brief Get the Mouse Pos object
 *
 * @return mouse_pos_t: {x, y}
 */
mouse_pos_t Engine::Hmi::HmiModule::getMousePos() const
{
    return _mouse_pos;
}

/**
 * @brief Check if the mouse is pressed.
 *
 * @return true
 * @return false
 */
bool Engine::Hmi::HmiModule::isMousePressed() const
{
    return _mouse_pressed;
}

/**
 * @brief Check if a key is pressed.
 *
 * @param key: up, down, left, right, space, escape
 * @return true
 * @return false
 */
bool Engine::Hmi::HmiModule::isKeyPressed(const std::string key) const
{
    if (strcmp(key.c_str(), "up"))
        return _keyboard[0];
    if (strcmp(key.c_str(), "down"))
        return _keyboard[1];
    if (strcmp(key.c_str(), "left"))
        return _keyboard[2];
    if (strcmp(key.c_str(), "right"))
        return _keyboard[3];
    if (strcmp(key.c_str(), "space"))
        return _keyboard[4];
    if (strcmp(key.c_str(), "escape"))
        return _keyboard[5];
    return false;
}
