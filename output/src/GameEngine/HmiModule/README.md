# HmiModule - Human-Machine Interface Module

## Overview

The `HmiModule` is a component of the R-Type project responsible for managing user input through a graphical user interface (GUI). It utilizes the Simple and Fast Multimedia Library (SFML) for graphics and window handling. This module facilitates the capture of mouse positions, mouse button states, and keyboard key states.

## Structure Explanation

### `mouse_pos_t` Struct

```cpp
typedef struct mouse_pos_s {
    unsigned int x;
    unsigned int y;
} mouse_pos_t;
```

This structure, `mouse_pos_t`, represents the coordinates of the mouse cursor. The `x` and `y` members hold the respective positions on the screen.

### `HmiModule` Class

```cpp
class HmiModule {
public:
    HmiModule(sf::RenderWindow* window);
    ~HmiModule();

    void update();

    mouse_pos_t getMousePos() const;
    bool isMousePressed() const;
    bool isKeyPressed(const std::string) const;

private:
    sf::RenderWindow _window;
    bool _mouse_pressed;
    mouse_pos_t _mouse_pos;
    std::bitset<6> _keyboard;
};
```

#### Public Methods

- **Constructor and Destructor**:
  - `HmiModule(sf::RenderWindow* window)`: Constructor initializing the module with an SFML `RenderWindow`.
  - `~HmiModule()`: Destructor for cleanup.

- `void update()`: Method to update the state of the HmiModule, capturing input events.

- `mouse_pos_t getMousePos() const`: Method returning the current mouse cursor position.

- `bool isMousePressed() const`: Method indicating whether the mouse button is pressed.

- `bool isKeyPressed(const std::string) const`: Method checking if a specific keyboard key is pressed. The key is identified by its name.

#### Private Members

- `sf::RenderWindow _window`: SFML window object for handling GUI-related functionalities.

- `bool _mouse_pressed`: Boolean flag indicating whether the mouse button is pressed.

- `mouse_pos_t _mouse_pos`: Struct holding the current mouse cursor position.

- `std::bitset<6> _keyboard`: Bitset representing the state of specific keyboard keys. The indices correspond to different keys (up, down, left, right, space, escape).

## Usage

To utilize the `HmiModule` in your R-Type project, create an instance of the class, passing an SFML `RenderWindow` to the constructor. Call the `update()` method in your main loop to capture and update input events. Access the mouse position, mouse button state, and keyboard key states using the provided methods.