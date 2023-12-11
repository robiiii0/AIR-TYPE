<# VelocityComponent - Physics Component

## Overview

The `VelocityComponent` class is a physics component within the R-Type project designed to represent the velocity attribute of entities. This component provides functionalities to manage and utilize the velocity information during the physics simulation.

## Structure Explanation

### `VelocityComponent` Class

```cpp
namespace Engine {
    namespace Physic {
        namespace Components {
            template<typename T>
            class VelocityComponent : public Engine::Entity::Component::AComponent {
            public:
                // Constructor for initializing the VelocityComponent with data.
                VelocityComponent(T data);

                // Destructor for cleanup.
                ~VelocityComponent();

                // Method to execute the velocity component's functionality.
                void execute() override;

                // Method to get the name of the velocity component.
                std::string getName() const override;

                // Method to set the velocity for the component.
                void setVelocity(std::pair<float, float> velocity);

            protected:
            private:
                std::pair<float, float> _velocity;
                std::string             _component_name;
                T                       data;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine
```

#### Public Methods

- **Constructor (`VelocityComponent(T data)`) and Destructor (`~VelocityComponent()`)**
  - The constructor initializes the `VelocityComponent` with the provided data.
  - The destructor is responsible for any necessary cleanup when the `VelocityComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the velocity component's functionality. This method is likely responsible for updating the entity's position based on its velocity.

- **`std::string getName() const`**
  - Method to get the name of the velocity component. The name provides identification for the type of component.

- **`void setVelocity(std::pair<float, float> velocity)`**
  - Method to set the velocity for the component. This allows external code to update the velocity attribute of the entity.

#### Private Members

- `_velocity`: A pair of floats representing the x and y components of the entity's velocity.
- `_component_name`: A string representing the name of the velocity component.
- `data`: Template parameter representing additional data associated with the velocity component.

#### Usage Example

```cpp
// Example usage of VelocityComponent
int initialData = 5;
Engine::Physic::Components::VelocityComponent<int> velocityComponent(initialData);

// Set velocity attribute
std::pair<float, float> newVelocity = {3.0f, 1.5f};
velocityComponent.setVelocity(newVelocity);

// Execute the velocity component's functionality
velocityComponent.execute();

// Get the name of the velocity component
std::string componentName = velocityComponent.getName();
```

In this example, a `VelocityComponent` instance is created with a template parameter of type `int`. The velocity attribute is set using the `setVelocity` method, and the component's functionality is executed with the `execute` method. The name of the component is retrieved using the `getName` method. Developers can customize the usage according to the physics requirements of the R-Type project.