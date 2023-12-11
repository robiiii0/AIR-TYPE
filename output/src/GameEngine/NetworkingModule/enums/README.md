# NetworkingTypeEnum - Networking Type Enumeration

## Overview

The `NetworkingTypeEnum` is an enumeration within the R-Type project designed to represent different networking types. This enumeration provides symbolic names for commonly used networking types, such as TCP and UDP.

## Structure Explanation

### `NetworkingTypeEnum` Enumeration

```cpp
enum NetworkingTypeEnum {
    TCP,
    UDP
};
```

#### Enumerators

- `TCP`: Symbolic name representing the TCP (Transmission Control Protocol) networking type.
- `UDP`: Symbolic name representing the UDP (User Datagram Protocol) networking type.

## Usage

The `NetworkingTypeEnum` enumeration is intended to be used within the R-Type project to specify the desired networking type for various networking components, such as client and server implementations.

### Example Usage

```cpp
#include "NetworkingTypeEnum.hpp"

// Example usage with NetworkingTypeEnum
Engine::Network::NetworkingTypeEnum networkType = Engine::Network::TCP;

// Use the enumeration in networking code
if (networkType == Engine::Network::TCP) {
    // TCP networking code
} else if (networkType == Engine::Network::UDP) {
    // UDP networking code
}
```

In this example, the `NetworkingTypeEnum` is used to represent the desired networking type (`TCP` or `UDP`). The enumeration is then used in conditional statements to execute specific networking code based on the chosen networking type. Customize the usage according to the networking requirements of your project.