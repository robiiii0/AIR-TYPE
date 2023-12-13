# WindowComponent - Window Handling Component

## Overview

The `Window` class within the R-Type project is a component designed to manage and manipulate the properties of an SFML window. This class encapsulates functionalities related to the window, such as setting size, title, icon, mouse cursor visibility, key repeat, and more.

## Structure Explanation

### `Window` Class

```cpp
namespace Engine {
    namespace RendererModule {
        class Window {
            public:
                // Constructor for initializing the Window instance.
                Window();

                // Destructor for cleanup.
                ~Window();

                // Method to set the size of the window.
                void setSize(sf::Vector2u size, sf::Window window);

                // Method to set the framerate limit of the window.
                void setFramerateLimit(unsigned int limit, sf::Window window);

                // Method to enable or disable vertical synchronization.
                void setVerticalSyncEnabled(bool enabled, sf::Window window);

                // Method to set the title of the window.
                void setTitle(std::string title, sf::Window window);

                // Method to set the icon of the window.
                void setIcon(sf::Image icon, sf::Window window);

                // Method to set the visibility of the mouse cursor.
                void setMouseCursorVisible(bool visible, sf::Window window);

                // Method to set whether the mouse cursor is grabbed.
                void setMouseCursorGrabbed(bool grabbed, sf::Window window);

                // Method to enable or disable key repeat.
                void setKeyRepeatEnabled(bool enabled, sf::Window window);

                // Method to request focus for the window.
                void requestFocus(sf::Window window);

                // Method to get the size of the window.
                sf::Vector2u getSize(sf::Window window) const;

                // Method to check if the window has focus.
                bool isFocus(sf::Window window) const;

                // Method to get the system-specific handle of the window.
                sf::WindowHandle getSystemHandle(sf::Window window) const;

            protected:
            private:
        };
    }  // namespace RendererModule
};      // namespace Engine
```

#### Public Methods

- **Constructor (`Window()`) and Destructor (`~Window()`)**
  - The constructor initializes the `Window` instance.
  - The destructor is responsible for any necessary cleanup when the `Window` instance is no longer needed.

- **`void setSize(sf::Vector2u size, sf::Window window)`**
  - Method to set the size of the window.

- **`void setFramerateLimit(unsigned int limit, sf::Window window)`**
  - Method to set the framerate limit of the window.

- **`void setVerticalSyncEnabled(bool enabled, sf::Window window)`**
  - Method to enable or disable vertical synchronization.

- **`void setTitle(std::string title, sf::Window window)`**
  - Method to set the title of the window.

- **`void setIcon(sf::Image icon, sf::Window window)`**
  - Method to set the icon of the window.

- **`void setMouseCursorVisible(bool visible, sf::Window window)`**
  - Method to set the visibility of the mouse cursor.

- **`void setMouseCursorGrabbed(bool grabbed, sf::Window window)`**
  - Method to set whether the mouse cursor is grabbed.

- **`void setKeyRepeatEnabled(bool enabled, sf::Window window)`**
  - Method to enable or disable key repeat.

- **`void requestFocus(sf::Window window)`**
  - Method to request focus for the window.

- **`sf::Vector2u getSize(sf::Window window) const`**
  - Method to get the size of the window.

- **`bool isFocus(sf::Window window) const`**
  - Method to check if the window has focus.

- **`sf::WindowHandle getSystemHandle(sf::Window window) const`**
  - Method to get the system-specific handle of the window.

#### Usage Example

```cpp
// Example usage of WindowComponent
Engine::RendererModule::Window windowComponent;

// Set the size of the window
sf::Vector2u newSize(800, 600);
windowComponent.setSize(newSize, mySFMLWindow);

// Set the framerate limit
unsigned int newLimit = 60;
windowComponent.setFramerateLimit(newLimit, mySFMLWindow);

// Enable vertical synchronization
windowComponent.setVerticalSyncEnabled(true, mySFMLWindow);

// Set the title of the window
std::string newTitle = "R-Type Game Window";
windowComponent.setTitle(newTitle, mySFMLWindow);

// ... (similarly, use other methods as needed)
```