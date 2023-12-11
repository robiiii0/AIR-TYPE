# DefenseComponent - Entity Defense Component

## Overview

The `DefenseComponent` is a specialized component within the R-Type project designed to manage the defense attributes of entities. This component is part of the game's entity framework, providing a modular and extensible way to handle various aspects related to entity defense.

## Structure Explanation

### `DefenseComponent` Class Template

```cpp
template<typename T>
class DefenseComponent : public Engine::Entity::Component::AComponent {
public:
    DefenseComponent(int data);
    ~DefenseComponent();
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
  - `DefenseComponent(int data)`: Constructor for initializing the `DefenseComponent` with relevant data.
  - `~DefenseComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute the defense behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `DefenseComponent`. It could represent defense strength, type, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the defense component.

## Usage

The `DefenseComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires defense behavior, an instance of `DefenseComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "DefenseComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::DefenseComponent<int> defenseComponent(30);

// Attach the DefenseComponent to an entity
entity.addComponent(defenseComponent);

// Game loop
while (true) {
    // Execute the defense behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, a `DefenseComponent` with an integer data type is created and attached to an entity. During the game loop, the entity's components, including the `DefenseComponent`, are executed, allowing the entity to perform its defense behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.