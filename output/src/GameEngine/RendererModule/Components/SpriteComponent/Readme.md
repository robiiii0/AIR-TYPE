# SpriteComponent - Rendering Component

## Overview

The `SpriteComponent` class is a rendering component within the R-Type project, specifically designed to handle sprite rendering using the Simple and Fast Multimedia Library (SFML). This component provides functionalities to manage sprite properties, such as rotation, scale, origin, texture rect, and texture attributes.

## Structure Explanation

### `SpriteComponent` Class

```cpp
namespace Engine {
    namespace RendererModule {
        namespace Components {
            class SpriteComponent :
                public Engine::Entity::Component::AComponent {
            public:
                // Constructor for initializing the SpriteComponent with a value.
                SpriteComponent(std::any value);

                // Destructor for cleanup.
                ~SpriteComponent();

                // Method to execute the sprite component's functionality.
                void execute() override;

                // Method to get the stored value as an any reference.
                std::any& get() override;

                // Method to get the name of the sprite component.
                std::string getName() const override;

                // Sprite properties

                // Method to set the rotation of the sprite.
                void setRotation(float rotation);

                // Method to set the scale of the sprite.
                void setScale(float x, float y);

                // Method to set the origin of the sprite.
                void setOrigin(float x, float y);

                // Method to set the texture rectangle of the sprite.
                void setTextureRect(const sf::IntRect& rect);

                // Texture properties

                // Method to set whether the texture is repeated or not.
                void setRepeated(bool repeated);

                // Method to set whether the texture is smooth or not.
                void setSmooth(bool smooth);

            protected:
            private:
                sf::Texture   _texture;
                sf::Sprite    _sprite;
                std::uint32_t _id;
                std::string   _component_name;
                std::string   _path;
                std::any      _ptr;
            };
        };  // namespace Components
    };      // namespace RendererModule
}  // namespace Engine
```

#### Public Methods

- **Constructor (`SpriteComponent(std::any value)`) and Destructor (`~SpriteComponent()`)**
  - The constructor initializes the `SpriteComponent` with the provided value.
  - The destructor is responsible for any necessary cleanup when the `SpriteComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the sprite component's functionality. This method is likely responsible for updating the sprite properties during rendering.

- **`std::any& get()`**
  - Method to get the stored value as an `any` reference. This allows external code to access and modify the internal data if needed.

- **`std::string getName() const`**
  - Method to get the name of the sprite component. The name provides identification for the type of component.

- **Sprite Properties**

  - **`void setRotation(float rotation)`**
    - Method to set the rotation of the sprite.

  - **`void setScale(float x, float y)`**
    - Method to set the scale of the sprite.

  - **`void setOrigin(float x, float y)`**
    - Method to set the origin of the sprite.

  - **`void setTextureRect(const sf::IntRect& rect)`**
    - Method to set the texture rectangle of the sprite.

- **Texture Properties**

  - **`void setRepeated(bool repeated)`**
    - Method to set whether the texture is repeated or not.

  - **`void setSmooth(bool smooth)`**
    - Method to set whether the texture is smooth or not.

#### Private Members

- `_texture`: An `sf::Texture` representing the texture associated with the sprite.
- `_sprite`: An `sf::Sprite` representing the rendering sprite.
- `_id`: An identifier for the sprite component.
- `_component_name`: A string representing the name of the sprite component.
- `_path`: A string representing the path to the texture (not used in the provided code).
- `_ptr`: An `any` type to store the value associated with the sprite component.

## Usage Example

```cpp
// Example usage of SpriteComponent
sf::Texture texture;
// ... load texture ...

Engine::RendererModule::Components::SpriteComponent spriteComponent(texture);
spriteComponent.setRotation(45.0f);
spriteComponent.setScale(2.0f, 2.0f);
spriteComponent.setOrigin(50.0f, 50.0f);
spriteComponent.setTextureRect(sf::IntRect(0, 0, 32, 32));
spriteComponent.setRepeated(true);
spriteComponent.setSmooth(true);
```