# AccelerationComponent - Physics Component

## Overview

The `AccelerationComponent` class is a physics component within the R-Type project designed to represent the acceleration attributes of entities. This component provides functionalities to manage and apply acceleration to entities during the physics simulation.

## Structure Explanation

### `AccelerationComponent` Class

```cpp
template<typename T>
class AccelerationComponent : public Engine::Entity::Component::AComponent {
public:
    // Constructor for initializing the AccelerationComponent with data.
    AccelerationComponent(T data);

    // Destructor for cleanup.
    ~AccelerationComponent();

    // Method to execute the acceleration component's functionality.
    void execute() override;

    // Method to get the name of the acceleration component.
    std::string getName() const override;

    // Method to set the acceleration for the component.
    void setAcceleration(std::pair<float, float> acceleration);

protected:
private:
    std::pair<float, float> _acceleration;
    std::string             _component_name;
    T                       data;
};
```

#### Public Methods

- **Constructor (`AccelerationComponent(T data)`) and Destructor (`~AccelerationComponent()`)**
  - The constructor initializes the `AccelerationComponent` with the provided data.
  - The destructor is responsible for any necessary cleanup when the `AccelerationComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the acceleration component's functionality. This method is likely responsible for applying the stored acceleration to the associated entity.

- **`std::string getName() const`**
  - Method to get the name of the acceleration component. The name provides identification for the type of component.

- **`void setAcceleration(std::pair<float, float> acceleration)`**
  - Method to set the acceleration for the component. This allows external code to update the acceleration attributes of the entity.

#### Private Members

- `_acceleration`: A pair of floats representing the acceleration attributes along the X and Y axes.
- `_component_name`: A string representing the name of the acceleration component.
- `data`: Template parameter representing additional data associated with the acceleration component.

#### Usage Example

```cpp
// Example usage of AccelerationComponent
Engine::Physic::Components::AccelerationComponent<float> accelerationComponent(2.5f);

// Set acceleration attributes
std::pair<float, float> acceleration = {1.0f, -0.5f};
accelerationComponent.setAcceleration(acceleration);

// Execute the acceleration component's functionality
accelerationComponent.execute();

// Get the name of the acceleration component
std::string componentName = accelerationComponent.getName();
```

In this example, an `AccelerationComponent` instance is created with a template parameter of type `float`. The acceleration attributes are set using the `setAcceleration` method, and the component's functionality is executed with the `execute` method. The name of the component is retrieved using the `getName` method. Developers can customize the usage according to the physics requirements of the R-Type project.