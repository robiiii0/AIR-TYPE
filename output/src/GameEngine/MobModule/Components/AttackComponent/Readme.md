# AttackComponent - Entity Attack Component

## Overview

The `AttackComponent` is a specialized component within the R-Type project that manages the attack behavior of entities. This component is designed to be part of the game's entity framework, providing a modular and extensible way to handle various aspects related to entity attacks.

## Structure Explanation

### `AttackComponent` Class Template

```cpp
template<typename T>
class AttackComponent : public Engine::Entity::Component::AComponent {
public:
    AttackComponent(int data);
    ~AttackComponent();
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
  - `AttackComponent(int data)`: Constructor for initializing the `AttackComponent` with relevant data.
  - `~AttackComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute the attack behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `AttackComponent`. It could represent attack power, type, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the attack component.

## Usage

The `AttackComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires attack behavior, an instance of `AttackComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "AttackComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::AttackComponent<int> attackComponent(50);

// Attach the AttackComponent to an entity
entity.addComponent(attackComponent);

// Game loop
while (true) {
    // Execute the attack behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, an `AttackComponent` with an integer data type is created and attached to an entity. During the game loop, the entity's components, including the `AttackComponent`, are executed, allowing the entity to perform its attack behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.