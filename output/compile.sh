#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo "Current directory: $CURRENT_DIR"

# Create a build directory if it doesn't exist
mkdir -p "$CURRENT_DIR/build"

# Run CMake to generate build files
cmake "$CURRENT_DIR/CMakeLists.txt"
echo "building cmake $CURRENT_DIR/CMakeLists"

# Build the project
make

not_compiled=0

if [ ! -e "$CURRENT_DIR/libengine_networking.a" ]; then
  echo "Networking library is missing"
  not_compiled=1
else
  echo "Networking library is present"
fi

if [ ! -e "$CURRENT_DIR/r-type_client" ]; then
  echo "Client binary is missing"
  not_compiled=1
else
  echo "Client binary is present"
fi

if [ ! -e "$CURRENT_DIR/r-type_server" ]; then
  echo "Server binary is missing"
  not_compiled=1
else
  echo "Server binary is present"
fi

if [ $not_compiled -eq 1 ]; then
  echo "One or more compilation(s) failed"
  exit 1
fi

echo "Compilation succeeded"
