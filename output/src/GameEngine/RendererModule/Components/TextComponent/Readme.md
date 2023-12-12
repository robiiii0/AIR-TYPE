# TextComponent - Rendering Component

## Overview

The `TextComponent` class is a rendering component within the R-Type project, designed to handle text rendering using the Simple and Fast Multimedia Library (SFML). This component provides functionalities to manage text properties, such as content, font, color, position, scale, rotation, and drawable characteristics.

## Structure Explanation

### `TextComponent` Class

```cpp
namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct TextData {
                    std::string  text;
                    sf::Font    &font;
                    sf::Color    color;
                    sf::Vector2f position;
                    sf::Vector2f scale;
                    float        rotation;
            };

            template<typename T>
            class TextComponent :
                public Engine::RendererModule::IRendererComponent {
            public:
                // Constructor for initializing the TextComponent with a value.
                TextComponent(T value);

                // Destructor for cleanup.
                ~TextComponent();

                // Method to execute the text component's functionality.
                void execute() override;

                // Method to get the name of the text component.
                std::string getName() const override;

                // Method to check if the text component is drawable.
                bool isDrawable() const override;

                // Method to get the SFML drawable object for rendering.
                sf::Drawable &getDrawable() override;

                // Method to set the text data for the component.
                void setTextData(TextData data);

                // Method to get the stored text data.
                TextData getTextData() const;

            protected:
            private:
                T        _data;
                sf::Text _text;
            };
        }  // namespace Components
    }      // namespace RendererModule
}  // namespace Engine
```

#### Public Methods

- **Constructor (`TextComponent(T value)`) and Destructor (`~TextComponent()`)**
  - The constructor initializes the `TextComponent` with the provided value.
  - The destructor is responsible for any necessary cleanup when the `TextComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the text component's functionality. This method is likely responsible for updating the text properties during rendering.

- **`std::string getName() const`**
  - Method to get the name of the text component. The name provides identification for the type of component.

- **`bool isDrawable() const`**
  - Method to check if the text component is drawable. This indicates whether the text should be included in the rendering process.

- **`sf::Drawable &getDrawable()`**
  - Method to get the SFML drawable object for rendering. This allows external code to access the drawable object for rendering.

- **`void setTextData(TextData data)`**
  - Method to set the text data for the component. The `TextData` structure contains information about the text content, font, color, position, scale, and rotation.

- **`TextData getTextData() const`**
  - Method to get the stored text data. This provides access to the current settings of the text.

#### Private Members

- `_data`: An object of template type representing additional data associated with the text component.
- `_text`: An `sf::Text` object representing the SFML text used for rendering.

#### Usage Example

```cpp
// Example usage of TextComponent
sf::Font font;
// ... load font ...

Engine::RendererModule::Components::TextComponent<int> textComponent(42);
TextData textData;
textData.text = "Hello, R-Type!";
textData.font = font;
textData.color = sf::Color::White;
textData.position = {100.0f, 200.0f};
textData.scale = {1.5f, 1.5f};
textData.rotation = 0.0f;
textComponent.setTextData(textData);
```