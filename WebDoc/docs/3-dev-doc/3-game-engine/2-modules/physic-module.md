# Physic Module

## Overview

The `PhysicModule` class is a component within the R-Type project designed to handle physics-related functionalities for entities. This class provides methods for updating the physics state and detecting collisions between entities.

<img src={require("../../../../assets/physic-module.png").default} />

## Structure Explanation

### `PhysicModule` Class

```cpp
template<typename T>
class PhysicModule {
public:
    // Constructor for initializing the PhysicModule.
    PhysicModule();

    // Destructor for cleanup.
    ~PhysicModule();

    // Method to update the physics state.
    void update();

    // Method to check if two entities are colliding.
    bool isColliding(Entity::Entity &entity1, Entity::Entity &entity2);

protected:
private:
};
```

#### Public Methods

- **Constructor (`PhysicModule()`) and Destructor (`~PhysicModule()`)**

  - The constructor initializes the `PhysicModule`.
  - The destructor is responsible for any necessary cleanup when the `PhysicModule` is no longer needed.

- **`void update()`**

  - Method to update the physics state. This method is likely responsible for advancing the physics simulation, applying forces, and handling other physics-related tasks.

- **`bool isColliding(Entity::Entity &entity1, Entity::Entity &entity2)`**
  - Method to check if two entities are colliding. This method likely performs collision detection based on the entities' positions, shapes, or other relevant attributes.

#### Private Members

- No private members are specified in the provided code snippet. The specific implementation details related to the physics calculations and data structures used are not detailed here.

#### Usage Example

```cpp
// Example usage of PhysicModule
Engine::Physic::PhysicModule<float> physicModule;

// Update the physics state
physicModule.update();

// Check for collision between two entities
Entity::Entity entity1;
Entity::Entity entity2;

bool collisionResult = physicModule.isColliding(entity1, entity2);
```

In this example, a `PhysicModule` instance is created with a template parameter of type `float`. The physics state is updated using the `update` method, and collision detection is performed between two entities using the `isColliding` method. Developers can customize the usage according to the physics requirements of the R-Type project.

This `PhysicModule` class is crucial for handling the physics aspects of entities within the game, providing a foundation for simulating realistic movements, collisions, and interactions.
