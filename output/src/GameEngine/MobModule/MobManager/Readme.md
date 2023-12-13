# MobManager - Mob Manager Module

## Overview

The `MobManager` is a component of the R-Type project responsible for managing mob entities within the game. It interacts with the `EntityManager` to handle the creation, updating, and destruction of mob entities.

## Structure Explanation

### `MobManager` Class

```cpp
class MobManager {
public:
    MobManager();
    ~MobManager();

protected:
private:
};
```

#### Public Methods

- **Constructor and Destructor**:
  - `MobManager()`: Constructor for initializing the `MobManager`.
  - `~MobManager()`: Destructor for cleanup.

## Usage

The `MobManager` works in conjunction with the `EntityManager` to handle mobile entities in the R-Type game. Mobile entities can include characters, enemies, or any other entities with dynamic movement.

### Integration with EntityManager

The `MobManager` communicates with the `EntityManager` to:

- Create and spawn mobile entities.
- Update the positions and states of mobile entities during the game loop.
- Handle the destruction of mobile entities when they are no longer needed.

### Example Usage

```cpp
#include "MobManager.hpp"

int main() {
    // Initialize EntityManager and MobManager
    Engine::EntityManager entityManager;
    Engine::MobModule::MobManager mobManager;

    // Spawn a mobile entity
    entityManager.spawnEntity("Player", 0, 0);

    // Game loop
    while (true) {
        // Update mobile entities
        mobManager.update();

        // Other game logic...

        // Update EntityManager
        entityManager.update();

        // Render the game
        // ...

        // Handle user input
        // ...

        // Check for collisions
        // ...
    }

    return 0;
}
```

In this example, the `MobManager` is used to manage mobile entities, working in harmony with the `EntityManager` to create a dynamic and interactive game environment. Feel free to extend the functionality of the `MobManager` as needed for your specific game requirements.