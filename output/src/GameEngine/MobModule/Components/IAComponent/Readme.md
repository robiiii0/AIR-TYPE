# IAComponent - Entity Artificial Intelligence Component

## Overview

The `IAComponent` is a specialized component within the R-Type project designed to implement artificial intelligence (AI) for entities. This component is part of the game's entity framework, providing a modular and extensible way to handle various aspects related to entity AI.

## Structure Explanation

### `IAComponent` Class Template

```cpp
template<typename T>
class IAComponent : public Engine::Entity::Component::AComponent {
public:
    IAComponent(int data);
    ~IAComponent();
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
  - `IAComponent(int data)`: Constructor for initializing the `IAComponent` with relevant data.
  - `~IAComponent()`: Destructor for cleanup.

- `void execute() override`: Method to execute AI-related behavior. Override from the base class.

- `std::string getName() const override`: Method to get the name of the component. Override from the base class.

#### Template Parameters

- `T`: Template parameter allowing flexibility in the type of data associated with the `IAComponent`. It could represent AI behavior, strategy, or any other relevant information.

#### Private Members

- `std::string _component_name`: String holding the name of the component.

- `T _data`: Templated data member representing the specific data associated with the AI component.

## Usage

The `IAComponent` is intended to be used as part of an entity's components within the R-Type project. When an entity requires AI-related behavior, an instance of `IAComponent` is attached to the entity through the entity framework.

### Example Usage

```cpp
#include "IAComponent.hpp"

// Example usage with an entity
Engine::MobModule::Components::IAComponent<int> iaComponent(2);

// Attach the IAComponent to an entity
entity.addComponent(iaComponent);

// Game loop
while (true) {
    // Execute AI-related behavior
    entity.executeComponents();

    // Other game logic...
}
```

In this example, an `IAComponent` with an integer data type is created and attached to an entity. During the game loop, the entity's components, including the `IAComponent`, are executed, allowing the entity to perform its AI-related behavior. Customize the template parameter `T` and the component's behavior according to the specific needs of your game.