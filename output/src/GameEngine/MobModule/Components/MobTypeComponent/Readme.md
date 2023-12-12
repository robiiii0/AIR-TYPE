# MobTypeComponent - Entity Mobile Type Component

## Overview

The `MobTypeComponent` is a specialized component within the R-Type project designed to define the type of mobile entities. This component is part of the game's entity framework, providing a modular and extensible way to handle various aspects related to the type of mobile entities.

## Structure Explanation

### `MobTypeComponent` Class Template

```cpp
template<typename T>
class MobTypeComponent : public Engine::Entity::Component::AComponent {
public:
    MobTypeComponent(int data);
    ~MobTypeComponent();
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
  - `MobTypeComponent(int data)`: Constructor for initializing the `MobTypeComponent` with relevant data.
  - `~MobTypeComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute type-related behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `MobTypeComponent`. It could represent the type of the mobile entity, category, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the mobile type component.

## Usage

The `MobTypeComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires type-related behavior, an instance of `MobTypeComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "MobTypeComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::MobTypeComponent<std::string> mobTypeComponent("Enemy");

// Attach the MobTypeComponent to an entity
entity.addComponent(mobTypeComponent);

// Game loop
while (true) {
    // Execute type-related behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, a `MobTypeComponent` with a string data type is created and attached to an entity. During the game loop, the entity's components, including the `MobTypeComponent`, are executed, allowing the entity to perform its type-related behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.