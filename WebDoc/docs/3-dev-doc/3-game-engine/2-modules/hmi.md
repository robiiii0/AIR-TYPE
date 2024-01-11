# HMI Module

## Description

The HMI module is a component of the GameEngine that manages the game's user interface. It provides a centralized interface for managing the game's user interface.

## Usage

To use the HMI in your game, follow these steps:

1. Initialize the HMI by creating an instance of it.

```cpp
Engine::Hmi::Hmi hmi;
```

2. Update the HMI by calling the `keyEvent` method.

```cpp
hmi.keyEvent(int keyCode);
```

3. Retrieve the HMI's state by calling the `getData` method.

```cpp
Engine::Hmi::HmiData data = hmi.getData();
```

Here`s an example of how to use the HMI:

```cpp
#include <array>

#include "Hmi/Hmi.hpp"

int main() {
    Engine::Hmi::Hmi hmi;

    hmi.keyEvent(1);
    data = hmi.getData();
    return 0;
}
```

## Documentation

```cpp
Hmi();
```
This constructor will init the HMI module.

```cpp
void keyEvent(int keyCode);
```
This method will update the HMI module with the given key code.

```cpp
HmiData getData();
```
This method will return the HMI module's state for the keyboard following this structure:

```cpp
struct HmiData {
            std::bitset<8> keyboard;
    };
```

## Authors

Valentin Woehrel