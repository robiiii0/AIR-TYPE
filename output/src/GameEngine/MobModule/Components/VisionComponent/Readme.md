# VisionComponent - Entity Vision Component

## Overview

The `VisionComponent` is a specialized component within the R-Type project designed to handle vision or visibility aspects of entities. This component is part of the game's entity framework, providing a modular and extensible way to manage various aspects related to entity vision.

## Structure Explanation

### `VisionComponent` Class Template

```cpp
template<typename T>
class VisionComponent : public Engine::Entity::Component::AComponent {
public:
    VisionComponent(int data);
    ~VisionComponent();
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
  - `VisionComponent(int data)`: Constructor for initializing the `VisionComponent` with relevant data.
  - `~VisionComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute vision-related behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `VisionComponent`. It could represent the vision range, type, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the vision component.

## Usage

The `VisionComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires vision-related behavior, an instance of `VisionComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "VisionComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::VisionComponent<int> visionComponent(100);

// Attach the VisionComponent to an entity
entity.addComponent(visionComponent);

// Game loop
while (true) {
    // Execute vision-related behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, a `VisionComponent` with an integer data type is created and attached to an entity. During the game loop, the entity's components, including the `VisionComponent`, are executed, allowing the entity to perform its vision-related behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.