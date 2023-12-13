# AnimationComponent - Rendering Component

## Overview

The `AnimationComponent` class is a rendering component within the R-Type project, specifically designed to handle sprite animations using the Simple and Fast Multimedia Library (SFML). This component provides functionalities to manage animations, update sprite frames, and retrieve information about the animation.

## Structure Explanation

### `AnimationComponent` Class

```cpp
namespace Engine {
    namespace RendererModule {
        namespace Components {
            class AnimationComponent :
                public Engine::Entity::Component::AComponent {
            public:
                // Constructor for initializing the AnimationComponent with a value.
                AnimationComponent(std::any value);

                // Destructor for cleanup.
                ~AnimationComponent();

                // Method to execute the animation component's functionality.
                void execute() override;

                // Method to get the stored value as an any reference.
                std::any& get() override;

                // Method to get the name of the animation component.
                std::string getName() const override;

                // Method to update the animation based on the delta time, number of frames, and the base rect.
                void update(float deltaTime, int nbFrame, int rectBase);

                // Method to get the current sprite rectangle.
                sf::IntRect getRect() const;

            private:
                std::uint32_t _id;
                std::string _component_name;
                std::any _ptr;
                sf::IntRect _rect;
                float _time;
            };
        };  // namespace Components
    };      // namespace RendererModule
}  // namespace Engine
```

#### Public Methods

- **Constructor (`AnimationComponent(std::any value)`) and Destructor (`~AnimationComponent()`)**
  - The constructor initializes the `AnimationComponent` with the provided value.
  - The destructor is responsible for any necessary cleanup when the `AnimationComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the animation component's functionality. This method is likely responsible for updating the animation state based on the elapsed time.

- **`std::any& get()`**
  - Method to get the stored value as an `any` reference. This allows external code to access and modify the internal data if needed.

- **`std::string getName() const`**
  - Method to get the name of the animation component. The name provides identification for the type of component.

- **`void update(float deltaTime, int nbFrame, int rectBase)`**
  - Method to update the animation based on the delta time, number of frames, and the base rectangle. This method is crucial for advancing the animation over time.

- **`sf::IntRect getRect() const`**
  - Method to get the current sprite rectangle. This information is vital for rendering the correct frame of the animation.

#### Private Members

- `_id`: An identifier for the animation component.
- `_component_name`: A string representing the name of the animation component.
- `_ptr`: An `any` type to store the value associated with the animation component.
- `_rect`: An `sf::IntRect` representing the current sprite rectangle.
- `_time`: A float indicating the elapsed time for animation updates.

## Usage Example

```cpp
// Example usage of AnimationComponent
sf::Texture texture;
// ... load texture ...

sf::Sprite sprite(texture);

Engine::RendererModule::Components::AnimationComponent animationComponent(sprite);
animationComponent.update(0.1f, 5, 32);  // Update animation with delta time, number of frames, and base rect.

// Get the current sprite rectangle
sf::IntRect currentRect = animationComponent.getRect();
```

In this example, an `AnimationComponent` instance is created with an `sf::Sprite` value. The animation is then updated using the `update` method, and the current sprite rectangle is obtained with the `getRect` method. Developers can customize the usage based on the rendering and animation requirements of the R-Type project.