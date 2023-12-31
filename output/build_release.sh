#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo "Current directory: $CURRENT_DIR"

mkdir -p "$CURRENT_DIR/release"

cmake -DCMAKE_BUILD_TYPE=Release "$CURRENT_DIR/CMakeLists.txt"
echo "building cmake $CURRENT_DIR/CMakeLists"

make

not_compiled=0

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

mv "$CURRENT_DIR/r-type_client" "$CURRENT_DIR/release/r-type_client"
mv "$CURRENT_DIR/r-type_server" "$CURRENT_DIR/release/r-type_server"

echo "Compilation succeeded"
