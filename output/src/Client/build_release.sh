#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

mkdir "$CURRENT_DIR/release"

cmake -B "$CURRENT_DIR/release" -S "$CURRENT_DIR" "-DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../../../vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Release

cmake --build "$CURRENT_DIR/release"

built=0

if [ ! -e "$CURRENT_DIR/release/Debug/r-type_client" ]; then
  echo "Linux/Mac Client binary is missing"
else
  echo "Linux/Mac Client binary is present"
  built=built+1
  mv "$CURRENT_DIR/release/Debug/r-type_client" "$CURRENT_DIR/../../release/r-type_client"
fi

if [ ! -e "$CURRENT_DIR/release/Debug/r-type_client.exe" ]; then
  echo "Windows Client binary is missing"
else
  echo "Windows Client binary is present"
  built=built+1
  mv "$CURRENT_DIR/release/Debug/r-type_client.exe" "$CURRENT_DIR/../../release/r-type_client.exe"
fi

if [ $built -eq 0 ]; then
  echo "Client Compilation failed"
  exit 1
fi
