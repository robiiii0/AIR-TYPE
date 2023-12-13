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

# Your binary check logic here
if [ ! -e "$CURRENT_DIR/r-type_client" ]; then
  echo "Client binary is missing"
  exit 1
fi

if [ ! -e "$CURRENT_DIR/r-type_server" ]; then
  echo "Server binary is missing"
  exit 1
fi

echo "Compilation succeeded"
