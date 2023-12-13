# StateComponent - Entity State Component

## Overview

The `StateComponent` is a specialized component within the R-Type project designed to manage the state attributes of entities. This component is part of the game's entity framework, providing a modular and extensible way to handle various aspects related to entity states.

## Structure Explanation

### `StateComponent` Class Template

```cpp
template<typename T>
class StateComponent : public Engine::Entity::Component::AComponent {
public:
    StateComponent(bool data);
    ~StateComponent();
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
  - `StateComponent(bool data)`: Constructor for initializing the `StateComponent` with relevant data.
  - `~StateComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute state-related behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `StateComponent`. It could represent the state of the entity, status, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the state component.

## Usage

The `StateComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires state-related behavior, an instance of `StateComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "StateComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::StateComponent<std::string> stateComponent("Idle");

// Attach the StateComponent to an entity
entity.addComponent(stateComponent);

// Game loop
while (true) {
    // Execute state-related behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, a `StateComponent` with a string data type is created and attached to an entity. During the game loop, the entity's components, including the `StateComponent`, are executed, allowing the entity to perform its state-related behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.