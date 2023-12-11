# PositionComponent - Physics Component

## Overview

The `PositionComponent` class is a physics component within the R-Type project designed to represent the position attribute of entities. This component provides functionalities to manage and utilize the position information during the physics simulation.

## Structure Explanation

### `PositionComponent` Class

```cpp
namespace Engine {
    namespace Physic {
        namespace Components {
            template<typename T>
            class PositionComponent : public Engine::Entity::Component::AComponent {
            public:
                // Constructor for initializing the PositionComponent with data and initial position.
                PositionComponent(T data, std::pair<float, float> initialPos);

                // Destructor for cleanup.
                ~PositionComponent();

                // Method to execute the position component's functionality.
                void execute() override;

                // Method to get the name of the position component.
                std::string getName() const override;

                // Method to set the position for the component.
                void setPos(std::pair<float, float> pos);

            protected:
            private:
                std::pair<float, float> _pos;
                std::string             _component_name;
                T                       data;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine
```

#### Public Methods

- **Constructor (`PositionComponent(T data, std::pair<float, float> initialPos)`) and Destructor (`~PositionComponent()`)**
  - The constructor initializes the `PositionComponent` with the provided data and an initial position.
  - The destructor is responsible for any necessary cleanup when the `PositionComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the position component's functionality. This method is likely responsible for utilizing the stored position information during physics calculations.

- **`std::string getName() const`**
  - Method to get the name of the position component. The name provides identification for the type of component.

- **`void setPos(std::pair<float, float> pos)`**
  - Method to set the position for the component. This allows external code to update the position attribute of the entity.

#### Private Members

- `_pos`: A pair of floats representing the x and y coordinates of the entity's position.
- `_component_name`: A string representing the name of the position component.
- `data`: Template parameter representing additional data associated with the position component.

#### Usage Example

```cpp
// Example usage of PositionComponent
float initialData = 10.0f;
std::pair<float, float> initialPosition = {20.0f, 30.0f};
Engine::Physic::Components::PositionComponent<int> positionComponent(initialData, initialPosition);

// Set position attribute
std::pair<float, float> newPosition = {25.0f, 35.0f};
positionComponent.setPos(newPosition);

// Execute the position component's functionality
positionComponent.execute();

// Get the name of the position component
std::string componentName = positionComponent.getName();
```

In this example, a `PositionComponent` instance is created with a template parameter of type `int`. The position attribute is set using the `setPos` method, and the component's functionality is executed with the `execute` method. The name of the component is retrieved using the `getName` method. Developers can customize the usage according to the physics requirements of the R-Type project.