# BoundingBoxComponent - Physics Component

## Overview

The `BoundingBoxComponent` class is a physics component within the R-Type project designed to represent the bounding box attributes of entities. This component provides functionalities to manage and utilize the bounding box information during the physics simulation.

## Structure Explanation

### `BoundingBoxComponent` Class

```cpp
namespace Engine {
    namespace Physic {
        namespace Components {
            struct Data {
                std::pair<float, float> _pos;
                std::pair<float, float> _size;
            };

            template<typename T>
            class BoundingBoxComponent : public Engine::Entity::Component::AComponent {
            public:
                // Constructor for initializing the BoundingBoxComponent with data.
                BoundingBoxComponent(Data data);

                // Destructor for cleanup.
                ~BoundingBoxComponent();

                // Method to execute the bounding box component's functionality.
                void execute() override;

                // Method to get the name of the bounding box component.
                std::string getName() const override;

                // Method to set the bounding box for the component.
                void setBoundingBox(Data data);

            protected:
            private:
                T           data;
                std::string _component_name;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine
```

#### Public Methods

- **Constructor (`BoundingBoxComponent(Data data)`) and Destructor (`~BoundingBoxComponent()`)**
  - The constructor initializes the `BoundingBoxComponent` with the provided data, representing the position and size of the bounding box.
  - The destructor is responsible for any necessary cleanup when the `BoundingBoxComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the bounding box component's functionality. This method is likely responsible for utilizing the stored bounding box information during physics calculations.

- **`std::string getName() const`**
  - Method to get the name of the bounding box component. The name provides identification for the type of component.

- **`void setBoundingBox(Data data)`**
  - Method to set the bounding box for the component. This allows external code to update the bounding box attributes of the entity.

#### Private Members

- `data`: Template parameter representing additional data associated with the bounding box component.
- `_component_name`: A string representing the name of the bounding box component.

#### Usage Example

```cpp
// Example usage of BoundingBoxComponent
Engine::Physic::Components::Data boundingBoxData = {
    {10.0f, 5.0f},  // Position
    {4.0f, 8.0f}    // Size
};

Engine::Physic::Components::BoundingBoxComponent<float> boundingBoxComponent(boundingBoxData);

// Set bounding box attributes
Engine::Physic::Components::Data newBoundingBoxData = {
    {15.0f, 6.0f},  // New position
    {5.0f, 10.0f}    // New size
};
boundingBoxComponent.setBoundingBox(newBoundingBoxData);

// Execute the bounding box component's functionality
boundingBoxComponent.execute();

// Get the name of the bounding box component
std::string componentName = boundingBoxComponent.getName();
```

In this example, a `BoundingBoxComponent` instance is created with a template parameter of type `float`. The bounding box attributes are set using the `setBoundingBox` method, and the component's functionality is executed with the `execute` method. The name of the component is retrieved using the `getName` method. Developers can customize the usage according to the physics requirements of the R-Type project.