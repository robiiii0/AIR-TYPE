# MassComponent - Physics Component

## Overview

The `MassComponent` class is a physics component within the R-Type project designed to represent the mass attribute of entities. This component provides functionalities to manage and utilize the mass information during the physics simulation.

## Structure Explanation

### `MassComponent` Class

```cpp
namespace Engine {
    namespace Physic {
        namespace Components {
            template<typename T>
            class MassComponent : public Engine::Entity::Component::AComponent {
            public:
                // Constructor for initializing the MassComponent with data.
                MassComponent(T data);

                // Destructor for cleanup.
                ~MassComponent();

                // Method to execute the mass component's functionality.
                void execute() override;

                // Method to get the name of the mass component.
                std::string getName() const override;

                // Method to set the mass for the component.
                void setMass(float mass);

            protected:
            private:
                float       _mass;
                std::string _component_name;
                T           data;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine
```

#### Public Methods

- **Constructor (`MassComponent(T data)`) and Destructor (`~MassComponent()`)**
  - The constructor initializes the `MassComponent` with the provided data, representing additional information associated with the mass.
  - The destructor is responsible for any necessary cleanup when the `MassComponent` is no longer needed.

- **`void execute()`**
  - Method to execute the mass component's functionality. This method is likely responsible for utilizing the stored mass information during physics calculations.

- **`std::string getName() const`**
  - Method to get the name of the mass component. The name provides identification for the type of component.

- **`void setMass(float mass)`**
  - Method to set the mass for the component. This allows external code to update the mass attribute of the entity.

#### Private Members

- `_mass`: A float representing the mass attribute of the entity.
- `_component_name`: A string representing the name of the mass component.
- `data`: Template parameter representing additional data associated with the mass component.

#### Usage Example

```cpp
// Example usage of MassComponent
float initialMass = 50.0f;
Engine::Physic::Components::MassComponent<int> massComponent(initialMass);

// Set mass attribute
float newMass = 60.0f;
massComponent.setMass(newMass);

// Execute the mass component's functionality
massComponent.execute();

// Get the name of the mass component
std::string componentName = massComponent.getName();
```

In this example, a `MassComponent` instance is created with a template parameter of type `int`. The mass attribute is set using the `setMass` method, and the component's functionality is executed with the `execute` method. The name of the component is retrieved using the `getName` method. Developers can customize the usage according to the physics requirements of the R-Type project.