# IRendererComponent - Rendering Component Interface

## Overview

The `IRendererComponent` class is an interface within the R-Type project, designed to define the common functionalities for rendering components. This interface ensures that any class inheriting from it implements the necessary methods for rendering within the R-Type project.

## Structure Explanation

### `IRendererComponent` Interface

```cpp
namespace Engine {
    namespace RendererModule {
        class IRendererComponent :
            public Engine::Entity::Component::AComponent {
                virtual bool          IsDrawable() const = 0;
                virtual sf::Drawable &Drawables() = 0;
        };
    }  // namespace RendererModule
}  // namespace Engine
```

#### Public Methods

- **`virtual bool IsDrawable() const = 0`**
  - Pure virtual method to check if the rendering component is drawable. Classes inheriting from this interface must provide an implementation to indicate whether the rendering component should be included in the rendering process.

- **`virtual sf::Drawable &Drawables() = 0`**
  - Pure virtual method to get the SFML drawable object for rendering. Classes inheriting from this interface must provide an implementation to return the SFML drawable object associated with the rendering component.

#### Usage Example

```cpp
// Example implementation of a class inheriting from IRendererComponent
class MyRendererComponent : public Engine::RendererModule::IRendererComponent {
public:
    bool IsDrawable() const override {
        // Implement the logic to determine if the component is drawable
        return true;
    }

    sf::Drawable &Drawables() override {
        // Implement the logic to return the SFML drawable object
        // associated with the rendering component
        return mySFMLDrawableObject;
    }
};
```