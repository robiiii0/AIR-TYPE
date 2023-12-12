# HealthComponent - Entity Health Component

## Overview

The `HealthComponent` is a specialized component within the R-Type project designed to manage the health attributes of entities. This component is part of the game's entity framework, providing a modular and extensible way to handle various aspects related to entity health.

## Structure Explanation

### `HealthComponent` Class Template

```cpp
template<typename T>
class HealthComponent : public Engine::Entity::Component::AComponent {
public:
    HealthComponent(HealthComponentData data);
    ~HealthComponent();
    void execute() override;
    std::string getName() const override;

protected:
private:
    std::string _component_name;
    T           _data;
};
```

#### Public Methods

- **Constructor and Destructor**:
  - `HealthComponent(HealthComponentData data)`: Constructor for initializing the `HealthComponent` with health-related data.
  - `~HealthComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute health-related behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `HealthComponent`. It could represent health strength, type, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the health component.

## Usage

The `HealthComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires health-related behavior, an instance of `HealthComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "HealthComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::HealthComponent<HealthComponentData> healthComponent({100, 100});

// Attach the HealthComponent to an entity
entity.addComponent(healthComponent);

// Game loop
while (true) {
    // Execute health-related behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, a `HealthComponent` with a `HealthComponentData` structure is created and attached to an entity. During the game loop, the entity's components, including the `HealthComponent`, are executed, allowing the entity to perform its health-related behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.